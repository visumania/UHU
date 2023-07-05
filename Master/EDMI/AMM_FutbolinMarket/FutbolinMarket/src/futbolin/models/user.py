from futbolin.db import db

class User(db.Model):
    nickname = db.Column(db.String(80), primary_key=True)
    email = db.Column(db.String(80), nullable=False)
    password = db.Column(db.String(16), nullable=False)
    token = db.Column(db.String(16), nullable=False)

    def __repr(self):
        return f'<User {self.nickname}>'