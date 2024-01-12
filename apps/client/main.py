import sys
import threading
from PyQt6.QtWidgets import QApplication
from forms.loginwin import LoginWin
from service.chatclient import ChatClient

app = QApplication(sys.argv)

win = LoginWin()
win.show()
client = ChatClient.instance()
client.set_logger_parent(win)
client_loop = threading.Thread(target=client.start)
client_loop.start()
ec = app.exec()

client.set_logger_parent(None)
client.notify_close()
client_loop.join()
sys.exit(ec)
