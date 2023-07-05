from flask import request
from flask_restful import Resource, reqparse
from futbolin.db import db
from futbolin.models.team import Team
from futbolin.routes.utils import verify_token

class TeamAPI(Resource):
    # create a new team
    def post(self):
        user = verify_token(request)
        if not user:
            return {'message': 'Unauthorized'}, 401
        
        parser = reqparse.RequestParser()
        parser.add_argument('name', type=str, required=True)
        parser.add_argument('country', type=str, required=True)
        parser.add_argument('squadValue', type=str, required=True)
        parser.add_argument('stadium', type=str, required=True)
        args = parser.parse_args()

        # check if team already exists
        team = Team.query.filter_by(name=args['name']).first()
        if team is not None:
            return {'message': 'Team already exists'}, 409
        
        # create new team and add to database
        new_team = Team(name=args['name'], country=args['country'], squadValue=args['squadValue'], stadium=args['stadium'])
        db.session.add(new_team)
        db.session.commit()

        return {'message': 'Team created successfully'}, 201
    
    def get(self):
        parser = reqparse.RequestParser()
        parser.add_argument('country', type=str, required=True)
        args = parser.parse_args()

        # get all info about all teams of a given country
        teams = Team.query.filter_by(country=args['country']).all()
        return [{'Name': team.name, 'Country': team.country, 'Squad market value': team.squadValue, 'Stadium name': team.stadium} for team in teams]
    
    def put(self, name):
        user = verify_token(request)
        if not user:
            return {'message': 'Unauthorized'}, 401

        parser = reqparse.RequestParser()
        parser.add_argument('squadValue', type=str, required=True)
        parser.add_argument('stadium', type=str, required=True)
        args = parser.parse_args()

        # chech if team exists
        dbTeam = Team.query.filter_by(name=name).first()
        if dbTeam is None:
            return {'message': 'Team not found'}, 404
        
        # update squadValue and stadium if provided
        if args['squadValue']:
            dbTeam.squadValue = args['squadValue']
        if args['stadium']:
            dbTeam.stadium = args['stadium']
        db.session.commit()

        return {'message': 'Team updated successfully'}, 200
    
    def delete(self, name):
        user = verify_token(request)
        if not user:
            return {'message': 'Unauthorized'}, 401
        
        dbTeam = Team.query.filter_by(name=name).first()

        if not dbTeam:
            return {'message': 'Team not found'}, 404
        
        db.session.delete(dbTeam)
        db.session.commit()

        return {}, 204