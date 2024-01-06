import sys
from PyQt6.QtWidgets import QApplication
from forms.loginwin import LoginWin

app = QApplication(sys.argv)
win = LoginWin()
win.show() 
sys.exit(app.exec())