from forms.ui.ui_loginwin import Ui_LoginWin
from qframelesswindow import FramelessMainWindow, StandardTitleBar
from PyQt6.QtCore import pyqtSlot
from utils.screen import ScreenUtil
from tools.tipbox import TipBox

MIN_ACCOUNT_LEN = 4
MAX_ACCOUNT_LEN = 8

MIN_PASSWORD_LEN = 4
MAX_PASSWORD_LEN = 12

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
            TipBox.warning(f'账号长度必须在{MIN_ACCOUNT_LEN}-{MAX_ACCOUNT_LEN}个字符内!', self)
            return
        if not MAX_PASSWORD_LEN >= len(self.__ui.edit_password.text()) >= MIN_PASSWORD_LEN:
            TipBox.warning(f'密码长度必须在{MAX_PASSWORD_LEN}-{MIN_PASSWORD_LEN}个字符内!', self)
            return