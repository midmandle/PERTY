import requests
import json
import unittest
#The addition of these tests requires the docker container to be run with this command: docker run --net="host"  --rm -it python-dev
class faasFunctionsTests(unittest.TestCase):
    def setUp(self):
        self.estimate = 3.0
        self.optimistic = 1.0
        self.pessimistic = 12.0

    def tearDown(self):
        self.estimate = 0
        self.optimistic = 0
        self.pessimistic = 0

    def test_func_expected_duration(self):
        jsonData = {"estimate":self.estimate, "optimistic":self.optimistic, "pessimistic":self.pessimistic}
        r = requests.post('http://127.0.0.1:8080/function/func_expected-duration', json = jsonData)

        jsonResponse = r.json()
        self.assertEqual(jsonResponse["expected"], 4.17)

    def test_func_standard_deviation(self):
        jsonData = {"estimate":self.estimate, "optimistic":self.optimistic, "pessimistic":self.pessimistic}
        r = requests.post('http://127.0.0.1:8080/function/func_standard-deviation', json = jsonData)

        jsonResponse = r.json()
        self.assertEqual(jsonResponse["standardDeviation"], 1.83)

    def test_func_best_case_estimate(self):
        jsonData = {"expectedDuration": 4.17, "standardDeviation":1.83, "multiplier":1}
        r = requests.post('http://127.0.0.1:8080/function/func_best-case-estimate', json = jsonData)

        jsonResponse = r.json()
        self.assertEqual(jsonResponse["bestCaseEstimate"], 2.34)

    def test_func_worst_case_estimate(self):
        jsonData = {"expectedDuration": 4.17, "standardDeviation":1.83, "multiplier":1}
        r = requests.post('http://127.0.0.1:8080/function/func_worst-case-estimate', json = jsonData)

        jsonResponse = r.json()
        self.assertEqual(jsonResponse["worstCaseEstimate"], 6.0)

    def test_func_priority_calculation(self):
        jsonData = {"time":4.17,"weight":3}
        r = requests.post('http://127.0.0.1:8080/function/func_priority-calculation', json = jsonData)

        jsonResponse = r.json()
        self.assertEqual(jsonResponse["priority"], 0.72)

    '''
    def test_func_add_task(self):
        jsonData = {"db":"user1", "host":"localhost", "username":"user1"}
        jsonData["title"]="Unit Testing Test 1"
        jsonData["description"]="Unit testing description string..."
        jsonData["optimistic"] = self.optimistic
        jsonData["estimate"] = self.estimate
        jsonData["pessimistic"] = self.pessimistic
        jsonData["multiplier"] = 1.0
        jsonData["weight"] = 3
        r = requests.post('http://127.0.0.1:8080/function/add-task', json = jsonData)
        jsonResponse = r.json()
        print jsonResponse
    '''
