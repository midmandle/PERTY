from mongoengine import *
import os, sys
sys.path.append("../")

class User(Document):
    username = StringField(max_length=100, required=True, unique=True, primary_key=True)
    first_name = StringField(max_length=100, required=True)
    last_name = StringField(max_length=100, required=True)
