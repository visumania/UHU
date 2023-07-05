from flask import request, Response, current_app, stream_with_context
from flask_restful import Resource, reqparse
from futbolin.db import db
from futbolin.models.match import Match
import time

# define the MatchStreamAPI resource
class MatchStreamAPI(Resource):
    def get(self):
        # get all matches
        print(current_app)

        def generate():
            diccionario = dict()

            while True:
                matches = Match.query.filter_by().all()

                for match in matches:
                    if match.id not in diccionario.keys() or match.result != diccionario[match.id]:
                        diccionario[match.id] = match.result
                        yield f'{{"localTeam": "{match.localTeam}. "awayTeam": "{match.awayTeam}", "competition": "{match.competition}", "date": "{match.date}", "time": "{match.time}", "result": "{match.result}"}}'

                yield '{}\n'
                time.sleep(3)
    
        return Response(stream_with_context(generate()), mimetype='application/x-ndjson')