from flask import request
from flask_restful import Resource, reqparse
from futbolin.db import db
from futbolin.models.user import User
from futbolin.routes.utils import generate_token, verify_token

class UserAPI(Resource):
    # create a new user
    def post(self):
        parser = reqparse.RequestParser()
        parser.add_argument('nickname', type=str, required=True)
        parser.add_argument('email', type=str, required=True)
        parser.add_argument('password', type=str, required=True)
        args = parser.parse_args()

        # check if user already exists
        user = User.query.filter_by(nickname=args['nickname']).first()
        if user is not None:
            return {'message': 'User already exists'}, 409
        
        token = generate_token()
        
        # create a new user and add to database
        new_user = User(nickname=args['nickname'], email=args['email'], password=args['password'], token=token)
        db.session.add(new_user)
        db.session.commit()

        return {'message': 'User created successfully','Your access token is': token}, 201
    
    def put(self):
        # check the credentials of the user
        dbUser = verify_token(request)
        if not dbUser:
            return {'message': 'Unauthorized'}, 401
        
        parser = reqparse.RequestParser()
        parser.add_argument('email', type=str, required=True)
        parser.add_argument('password', type=str, required=True)
        args = parser.parse_args()

        # update user email and password if provided
        if args['email']:
            dbUser.email = args['email']
        if args['password']:
            dbUser.password = args['password']
        db.session.commit()

        return{'message': 'User updated'}, 200
