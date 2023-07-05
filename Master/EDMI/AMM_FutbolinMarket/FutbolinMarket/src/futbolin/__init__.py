from flask import Flask
from flask_restful import Api

def create_app():
    app = Flask(__name__)
    api = Api(app)

    # load configuration settings
    app.config.from_object('futbolin.config.Config')

    #initialize database
    from futbolin.db import init_db
    from futbolin.models.user import User
    from futbolin.models.team import Team
    from futbolin.models.player import Player
    from futbolin.models.match import Match
    init_db(app)

    from futbolin.routes.user import UserAPI
    from futbolin.routes.team import TeamAPI
    from futbolin.routes.player import PlayerAPI
    from futbolin.routes.match import MatchAPI
    from futbolin.routes.matchstream import MatchStreamAPI
    api.add_resource(UserAPI, '/users')
    api.add_resource(TeamAPI, '/teams', '/teams/<string:name>')
    api.add_resource(PlayerAPI, '/players', '/players/<string:team>/<string:name>')
    api.add_resource(MatchAPI, '/matches', '/matches/<string:nameLocalTeam>/<string:nameAwayTeam>/<string:matchDate>')
    api.add_resource(MatchStreamAPI, '/matches-stream')

    return app