from res.ui.ui_fatalbox import Ui_FatalBox
from qframelesswindow import FramelessMainWindow, StandardTitleBar
from PyQt6.QtCore import pyqtSlot

class FatalBox(FramelessMainWindow):
    def __init__(self, errmsg, title, restart_app_path):
        super().__init__(None)
        self.__restart_app_path = restart_app_path
        self.__ui = Ui_FatalBox()
        self.__ui.setupUi(self)
        self.__ui.edit_errmsg.setPlainText(errmsg)
        self.setTitleBar(StandardTitleBar(self))
        self.setWindowTitle(title)