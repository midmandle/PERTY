import requests
import json

def handle(req):
    json_req = json.loads(req)
    weight = json_req["weight"]
    time = json_req["time"]

    if time <= 0:
        results = {"priority" : weight}
    else:
        priority = weight / time
        priority = round(priority, 2)
        results = {"priority" : priority}

    print json.dumps(results)
