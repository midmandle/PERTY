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

class OptionOne(Screen):
    pass

class OptionTwo(Screen):
    pass

sm = ScreenManager()

sm.add_widget(RootLayout(name="root"))
sm.add_widget(OptionOne(name="option1"))
sm.add_widget(OptionTwo(name="option2"))

#Main App class.
class MainApp(App):
    def build(self):
        return sm

#Run the UI
mainApp = MainApp()
mainApp.run()
