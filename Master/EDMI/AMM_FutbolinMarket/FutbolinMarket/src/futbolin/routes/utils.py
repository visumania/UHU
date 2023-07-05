from flask import request
from futbolin.models.user import User
import random
import string
import base64

def generate_token():
    # defines the possible characters for the token
    characters = string.ascii_letters + string.digits

    #generate a random seed for the random number generator.
    random_seed = random.randint(1, 100000)
    random.seed(random_seed)

    # generates the token using random characters
    token = ''.join(random.choice(characters) for _ in range(16))

    return token

def verify_token(request:request):
    encoded = request.headers.get('Authorization')
    encoded = encoded[6:]
    decoded_string = base64.b64decode(encoded).decode()    
    nickname, token = decoded_string.split(':')

    # check the credentials given in users database
    dbUser = User.query.filter_by(nickname=nickname, token=token).first()
    if dbUser is None:
        return None
    
    return dbUser
    