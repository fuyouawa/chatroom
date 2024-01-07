import sys
import threading
from PyQt6.QtWidgets import QApplication
from forms.loginwin import LoginWin
from service.chatclient import chat_client


app = QApplication(sys.argv)
client_loop = threading.Thread(target=chat_client.start)
client_loop.start()

win = LoginWin()
win.show()
ec = app.exec()

chat_client.notify_close()
client_loop.join()
sys.exit(ec)