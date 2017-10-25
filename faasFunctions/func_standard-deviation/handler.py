import json

def handle(req):
    json_req = json.loads(req)
    estimate = json_req["estimate"]
    optimistic = json_req["optimistic"]
    pessimistic = json_req["pessimistic"]

    stdDev = (pessimistic - optimistic) / 6.0
    stdDev = round(stdDev, 2)
    results = {"standardDeviation" : stdDev}

    print json.dumps(results)
