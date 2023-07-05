from flask import request
from flask_restful import Resource, reqparse
from futbolin.db import db
from futbolin.models.player import Player
from futbolin.models.team import Team
from futbolin.routes.utils import verify_token

class PlayerAPI(Resource):
    # create a new player
    def post(self):
        user = verify_token(request)
        if not user:
            return {'message': 'Unauthorized'}, 401
        
        parser = reqparse.RequestParser()
        parser.add_argument('team', type=str, required=True)
        parser.add_argument('shirtNumber', type=str, required=True)
        parser.add_argument('name', type=str, required=True)
        parser.add_argument('position', type=str, required=True)
        parser.add_argument('birthday', type=str, required=True)
        parser.add_argument('birthplace', type=str, required=True)
        parser.add_argument('marketValue', type=str, required=True)
        parser.add_argument('injured', type=bool, required=True)
        args = parser.parse_args()

        # check if the player already exists
        player = Player.query.filter_by(name=args['name'], team=args['team'], shirtNumber=args['shirtNumber']).first()
        if player is not None:
            return {'message': 'Player already exists'}, 409
        
        # check if the team provided exists
        dbTeam =Team.query.filter_by(name=args['team']).first()
        if dbTeam is None:
            return {'message': 'Team not found, firstly create it'}, 404
        
        # create new player and add to database
        new_player = Player(team=args['team'], shirtNumber=args['shirtNumber'], name=args['name'], position=args['position'], birthday=args['birthday'], birthplace=args['birthplace'], marketValue=args['marketValue'], injured=args['injured'])
        db.session.add(new_player)
        db.session.commit()

        return {'message': 'Player created sucessfully'}, 201
    
    def get(self):
        parser = reqparse.RequestParser()
        parser.add_argument('team', type=str, required=True)
        args = parser.parse_args()

        # get all the info about all players of a given team
        players = Player.query.filter_by(team=args['team']).all()
        return [{'Name': player.name, 'Team': player.team, 'Shirt number': player.shirtNumber, 'Position': player.position, 'Birthday': player.birthday, 'Birthplace': player.birthplace, 'Market value': player.marketValue, 'Injured': player.injured} for player in players]
    
    def put(self, team, name):
        user = verify_token(request)
        if not user:
            return {'message': 'Unauthorized'}, 401
        
        parser = reqparse.RequestParser()
        parser.add_argument('team', type=str, required=True)
        parser.add_argument('shirtNumber', type=int, required=False)
        parser.add_argument('position', type=str, required=False)
        parser.add_argument('marketValue', type=str, required=False)
        parser.add_argument('injured', type=bool, required=False)
        args = parser.parse_args()

        # check if team exists
        dbTeam = Team.query.filter_by(name=team).first()
        if dbTeam is None:
            return {'message': 'Current team not found'}, 404
        
        dbTeam =Team.query.filter_by(name=args['team']).first()
        if dbTeam is None:
            return {'message': 'New team not found, firstly create it'}, 404

        # check if player exists
        dbPlayer = Player.query.filter_by(name=name).first()
        if dbPlayer is None:
            return {'message': 'Player not found'}, 404

        # update team, number, position, marketValue and injured if provided
        if args['team']:
            dbPlayer.team = args['team']
        if args['shirtNumber']:
            dbPlayer.shirtNumber = args['shirtNumber']
        if args['position']:
            dbPlayer.position = args['position']
        if args['marketValue']:
            dbPlayer.marketValue = args['marketValue']
        if args['injured']:
            dbPlayer.injured = args['injured']
        db.session.commit()

        return {'message': 'Player updated successfully'}, 200
    
    def delete(self, team, name):
        user = verify_token(request)
        if not user:
            return {'message': 'Unauthorized'}, 401
        
        # check if team exists
        dbTeam = Team.query.filter_by(name=team).first()
        if dbTeam is None:
            return {'message': 'Team not found'}, 404

        # check if player exists
        dbPlayer = Player.query.filter_by(name=name).first()
        if dbPlayer is None:
            return {'message': 'Player not found'}, 404
        
        db.session.delete(dbPlayer)
        db.session.commit()

        return {}, 204