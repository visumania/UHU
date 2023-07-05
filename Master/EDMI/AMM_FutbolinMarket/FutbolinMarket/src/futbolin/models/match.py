from futbolin.db import db

class Match(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    localTeam = db.Column(db.String(80), db.ForeignKey('team.name'), nullable=False)
    awayTeam = db.Column(db.String(80), db.ForeignKey('team.name'), nullable=False)
    competition = db.Column(db.String(80), nullable=False)
    result = db.Column(db.String(5), nullable=False)
    date = db.Column(db.String(10), nullable=False)
    time = db.Column(db.String(5), nullable=False)

    def __repr__(self):
        return f'<Match {self.id}>'