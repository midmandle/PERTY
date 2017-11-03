import json
from tasks_odm import Task
from mongoengine import *

def handle(req):
    json_req = json.loads(req)

    #monogoengine access info REQUIRED
    in_db = json_req["db"]
    in_username = json_req["username"]
    in_host = json_req["host"]

    connect(db=in_db, host=in_host)

    #Task data REQUIRED
    in_title = json_req["title"]
    in_description = json_req["description"]
    in_optimistic = json_req["optimistic"]
    in_estimate = json_req["estimate"]
    in_pessimistic = json_req["pessimistic"]
    in_multiplier = json_req["multiplier"]
    in_weight = json_req["weight"]

    task = Task()
    task.title=in_title
    task.description=in_description
    task.optimistic = in_optimistic
    task.estimate = in_estimate
    task.pessimistic = in_pessimistic
    task.multiplier = in_multiplier
    task.weight = in_weight
    task.save()


    #Calculate Task calculated values
    #expected
    jsonData = {"estimate":task.estimate, "optimistic":task.optimistic, "pessimistic":task.pessimistic}
    r = requests.post('http://127.0.0.1:8080/function/func_expected-duration', json = jsonData)
    json_response = r.json()
    task.expected = json_response['expected']
    task.save()

    #stdDev
    jsonData = {"estimate":task.estimate, "optimistic":task.optimistic, "pessimistic":task.pessimistic}
    r = requests.post('http://127.0.0.1:8080/function/func_standard-deviation', json = jsonData)
    json_response = r.json()
    task.stdDev = json_response['standardDeviation']
    task.save()

    #bestCase
    jsonData = {"expectedDuration": task.expected, "standardDeviation": task.stdDev, "multiplier": task.multiplier}
    r = requests.post('http://127.0.0.1:8080/function/func_best-case-estimate', json = jsonData)
    json_response = r.json()
    task.bestCase = json_response['bestCaseEstimate']
    task.save()

    #worstCase
    jsonData = {"expectedDuration": task.expected, "standardDeviation": task.stdDev, "multiplier": task.multiplier}
    r = requests.post('http://127.0.0.1:8080/function/func_worst-case-estimate', json = jsonData)
    json_response = r.json()
    task.bestCase = json_response['worstCaseEstimate']
    task.save()

    #priorityBest
    jsonData = {"time":task.bestCase,"weight":task.weight}
    r = requests.post('http://127.0.0.1:8080/function/func_priority-calculation', json = jsonData)
    json_response = r.json()
    task.priorityBest = json_response['priority']
    task.save()

    #priorityExpected
    jsonData = {"time":task.expected,"weight":task.weight}
    r = requests.post('http://127.0.0.1:8080/function/func_priority-calculation', json = jsonData)
    json_response = r.json()
    task.priorityExpected = json_response['priority']
    task.save()

    #priorityWorst
    jsonData = {"time":task.worstCase,"weight":task.weight}
    r = requests.post('http://127.0.0.1:8080/function/func_priority-calculation', json = jsonData)
    json_response = r.json()
    task.priorityWorst = json_response['priority']
    task.save()

    print json.dumps(Task.objects)
