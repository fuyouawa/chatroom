import sys
import threading
from PyQt6.QtWidgets import QApplication
from forms.loginwin import LoginWin
from service.chatclient import ChatClient

app = QApplication(sys.argv)

client = ChatClient.instance()
client_loop = threading.Thread(target=client.start)
client_loop.start()

win = LoginWin()
win.show()
ec = app.exec()

client.notify_close()
client_loop.join()
sys.exit(ec)