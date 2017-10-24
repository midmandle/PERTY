import kivy

#Load all the .kv files automagically.
from kivy.lang import Builder
from os import listdir
kv_path = './kv/'
for kv in listdir(kv_path):
    Builder.load_file(kv_path+kv)

#File specific imports.
from kivy.app import App
from kivy.uix.screenmanager import ScreenManager, Screen

#Main layout
class RootLayout(Screen):
    pass

#Screen layout for AddTask
class AddTask(Screen):
    pass

#Screen layout for AddTask
class AddTaskList(Screen):
    pass

#Screen layout for NewWorkflow
class NewWorkflow(Screen):
    pass

#Add screens to screen manager for management.
sm = ScreenManager()

sm.add_widget(RootLayout(name="root"))
sm.add_widget(AddTask(name="addTask"))
sm.add_widget(AddTaskList(name="addTaskList"))
sm.add_widget(NewWorkflow(name="newWorkflow"))

#Main App class.
class MainApp(App):
    def build(self):
        return sm

#Run the UI
mainApp = MainApp()
mainApp.run()