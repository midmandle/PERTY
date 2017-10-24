import requests
import json

def handle(req):
    json_req = json.loads(req)
    expectedDuration = json_req["expectedDuration"]
    standardDeviation = json_req["standardDeviation"]
    multiplier = json_req["multiplier"]

    bestCaseEstimate = expectedDuration - (multiplier * standardDeviation)
    bestCaseEstimate = round(bestCaseEstimate, 2)

    results = {"bestCaseEstimate" : bestCaseEstimate}

    print json.dumps(results)
