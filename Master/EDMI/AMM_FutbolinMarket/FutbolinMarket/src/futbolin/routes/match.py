from flask import request
from flask_restful import Resource, reqparse
from futbolin.db import db
from futbolin.models.match import Match
from futbolin.models.team import Team
from futbolin.routes.utils import verify_token
from sqlalchemy.sql.expression import or_

class MatchAPI(Resource):
    # create a new match
    def post(self):
        user = verify_token(request)
        if not user:
            return {'message': 'Unauthorized'}, 401
        
        parser = reqparse.RequestParser()
        parser.add_argument('localTeam', type=str, required=True)
        parser.add_argument('awayTeam', type=str, required=True)
        parser.add_argument('competition', type=str, required=True)
        parser.add_argument('result', type=str, required=True)
        parser.add_argument('date', type=str, required=True)
        parser.add_argument('time', type=str, required=True)
        args = parser.parse_args()

        # check if teams provided exist
        dbLocalTeam = Team.query.filter_by(name=args['localTeam']).first()
        if dbLocalTeam is None:
            return {'message': 'Local team not found, firstly create it'}, 404
        
        dbAwayTeam = Team.query.filter_by(name=args['awayTeam']).first()
        if dbAwayTeam is None:
            return {'message': 'Away team not found, firstly create it'}, 404

        # check if the match already exits
        match = Match.query.filter_by(localTeam=args['localTeam'], awayTeam=args['awayTeam'], date=args['date']).first()
        if match is not None:
            return {'message': 'Match already exists'}, 409
        
        # create new match and add to database
        new_match = Match(localTeam=args['localTeam'], awayTeam=args['awayTeam'], competition=args['competition'], result=args['result'], date=args['date'], time=args['time'])
        db.session.add(new_match)
        db.session.commit()

        return {'message': 'Match created successfully'}, 201
    
    def get(self):
        parser = reqparse.RequestParser()
        parser.add_argument('team', type=str, required=True)
        args = parser.parse_args()

        # get all the matches of a given team
        localMatches = Match.query.filter_by(localTeam=args['team']).all()
        awayMatches = Match.query.filter_by(awayTeam=args['team']).all()
        return[{'Local team': lMatch.localTeam, 'Away team': lMatch.awayTeam, 'Competition': lMatch.competition, 'Result': lMatch.result, 'Date': lMatch.date, 'Time': lMatch.time} for lMatch in localMatches] + [{'Local team': aMatch.localTeam, 'Away team': aMatch.awayTeam, 'Competition': aMatch.competition, 'Result': aMatch.result, 'Date': aMatch.date, 'Time': aMatch.time} for aMatch in awayMatches]
    
    def put(self, nameLocalTeam, nameAwayTeam, matchDate):
        user = verify_token(request)
        if not user:
            return {'message': 'Unauthorized'}, 401
        
        parser = reqparse.RequestParser()
        parser.add_argument('result', type=str, required=True)
        args = parser.parse_args()

        # check if local team exists
        dbLocalTeam = Team.query.filter_by(name=nameLocalTeam).first()
        if dbLocalTeam is None:
            return {'message': 'Local team not found'}, 404

        # check if away team exists
        dbAwayTeam = Team.query.filter_by(name=nameAwayTeam).first()
        if dbAwayTeam is None:
            return {'message': 'Away team not found'}, 404
        
        # check if the match exists
        matchDate = matchDate.replace('-', '/')
        dbMatch = Match.query.filter_by(localTeam=nameLocalTeam, awayTeam=nameAwayTeam, date=matchDate).first()
        if dbMatch is None:
            return {'message': 'Match not found'}, 404

        #update the result of the match
        if args['result']:
            dbMatch.result = args['result']
        db.session.commit()

        return {'message': 'Match result updated successfully'}, 200
    
    def delete(self, nameLocalTeam, nameAwayTeam, matchDate):
        user = verify_token(request)
        if not user:
            return {'message': 'Unauthorized'}, 401
        
        # check if local team exists
        dbLocalTeam = Team.query.filter_by(name=nameLocalTeam).first()
        if dbLocalTeam is None:
            return {'message': 'Local team not found'}, 404

        # check if away team exists
        dbAwayTeam = Team.query.filter_by(name=nameAwayTeam).first()
        if dbAwayTeam is None:
            return {'message': 'Away team not found'}, 404

        # check if the match exists
        matchDate = matchDate.replace('-', '/')
        dbMatch = Match.query.filter_by(localTeam=nameLocalTeam, awayTeam=nameAwayTeam, date=matchDate).first()
        if dbMatch is None:
            return {'message': 'Match not found'}, 404
        
        db.session.delete(dbMatch)
        db.session.commit()

        return {}, 204