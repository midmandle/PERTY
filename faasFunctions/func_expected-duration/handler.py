import requests
import json

def handle(req):
    json_req = json.loads(req)
    estimate = json_req["estimate"]
    optimistic = json_req["optimistic"]
    pessimistic = json_req["pessimistic"]

    expectedValue = (optimistic + (4 * estimate) + pessimistic) / 6.0
    expectedValue = round(expectedValue,2)
    results = {"expected" : expectedValue}

    print json.dumps(results)
