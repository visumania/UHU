from futbolin.db import db

class Player(db.Model):
    #id = db.Column(db.Integer, primary_key=True)
    team = db.Column(db.String(80), db.ForeignKey('team.name'), nullable=False)
    shirtNumber = db.Column(db.Integer, nullable=False)
    name = db.Column(db.String(80), primary_key=True)
    position = db.Column(db.String(30), nullable=False)
    birthday = db.Column(db.String(10), nullable=False)
    birthplace = db.Column(db.String(80), nullable=False)
    marketValue = db.Column(db.String(20), nullable=False)
    injured = db.Column(db.Boolean, nullable=False)

    def __repr__(self):
        return f'<Player {self.name}>'

