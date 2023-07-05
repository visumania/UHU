from futbolin.db import db

class Team(db.Model):
    name = db.Column(db.String(80), primary_key=True)
    country = db.Column(db.String(80), nullable=False)
    squadValue = db.Column(db.String(20), nullable=False)
    stadium = db.Column(db.String(80), nullable = False)

    def __repr__(self):
        return f'<Team {self.name}>'