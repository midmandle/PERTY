import requests
import json

def handle(req):
    json_req = json.loads(req)
    expectedDuration = json_req["expectedDuration"]
    standardDeviation = json_req["standardDeviation"]
    multiplier = json_req["multiplier"]

    worstCaseEstimate = expectedDuration + (multiplier * standardDeviation)
    worstCaseEstimate = round(worstCaseEstimate, 2)

    results = {"worstCaseEstimate" : worstCaseEstimate}

    print json.dumps(results)
