from forms.ui.ui_loginwin import Ui_LoginWin
from qframelesswindow import FramelessMainWindow, StandardTitleBar
from PyQt6.QtCore import pyqtSlot
from PyQt6.QtWidgets import QMessageBox
from utils.screen import ScreenUtil
from basic.const import MAX_ACCOUNT_LEN, MIN_ACCOUNT_LEN, MAX_PASSWORD_LEN, MIN_PASSWORD_LEN
from tools.logger import Logger

class LoginWin(FramelessMainWindow):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.__ui = Ui_LoginWin()
        self.__ui.setupUi(self)
        self.setTitleBar(StandardTitleBar(self))
        self.setWindowTitle('登录')
        self.move(ScreenUtil.central_point(self))


    @pyqtSlot()
    def on_btn_login_clicked(self):
        if not MAX_ACCOUNT_LEN >= len(self.__ui.edit_account.text()) >= MIN_ACCOUNT_LEN:
            Logger.warning(self, f'账号长度必须在{MIN_ACCOUNT_LEN}-{MAX_ACCOUNT_LEN}个字符内!')
            return
        if not MAX_PASSWORD_LEN >= len(self.__ui.edit_password.text()) >= MIN_PASSWORD_LEN:
            Logger.warning(self, f'密码长度必须在{MAX_PASSWORD_LEN}-{MIN_PASSWORD_LEN}个字符内!')
            return