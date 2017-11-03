from mongoengine import *

WEIGHT = (1,2,3,4,5)

class Task(Document):
    #User provided fields.
    title = StringField(required=True, max_length=250)
    description = StringField(max_length=500)
    optimistic = FloatField(required=True, default = 0.0)
    estimate = FloatField(required=True, default = 0.0)
    pessimistic = FloatField(required=True, default = 0.0)
    multiplier = FloatField(required=True, default = 1)
    weight = IntField(required=True, default = 1, choices=WEIGHT)
    #System calculated fields.
    expected = FloatField(default = 0.0)
    stdDev = FloatField(default = 0.0)
    bestCase = FloatField(default = 0.0)
    worstCase = FloatField(default = 0.0)
    priorityBest = FloatField(default = 0.0)
    priorityExpected = FloatField(default = 0.0)
    priorityWorst = FloatField(default = 0.0)
