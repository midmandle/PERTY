from mongoengine import *
import os, sys
sys.path.append("../")

class TaskList(Document):
    workflow_name = StringField(default="Anonymous Workflow", max_length=250)
    workflow_list = ListField(GenericReferenceField(choices=('Task', 'TaskList'), reverse_delete_ruler=mongoengine.PULL))
    item_count = IntField(default=0)
    task_count = IntField(default=0)
    tasklist_count = IntField(default=0)
