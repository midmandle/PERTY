from mongoengine import *
import os, sys
sys.path.append("../")

class TaskList(Document):
    listName = StringField(default="Anonymous List", max_length=250)
    taskCount = IntField(default=0)
    tasksInList = ListField(ReferenceField('Task', reverse_delete_ruler=mongoengine.PULL))
    bestCase = FloatField(default=0)
    expectedDuration = FloatField(defautl=0)
    worstCase = FloatField(default=0)

'''
def ODM_addTask(taskListRef, taskRef):
    connect('PERTY')
    currentTaskList = TaskList.objects(id=taskListRef)
    currentTaskList.update_one(push__tasksInList=taskRef)
    currentTaskList.taskCount += 1
    currentTaskList.save()

def ODM_removeTask(taskListRef, taskRef):
    connect('PERTY')
    currentTaskList = TaskList.objects(id=taskListRef)
    currentTaskList.update_one(pull__tasksInList=taskRef)
    currentTaskList.taskCount -= 1
    currentTaskList.save()
'''
