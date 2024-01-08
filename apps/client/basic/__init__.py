import os
import sys
from basic.app_paths import AppPaths
from PyQt6.QtWidgets import QMessageBox
try:
    from basic.config import config
except Exception as e:
    #TODO 初始化异常
    sys.exit(1)

user_home = os.path.expanduser('~')
AppPaths.APPDATA = os.path.join(user_home, 'AppData')
AppPaths.CACHE = os.path.join(AppPaths.APPDATA, 'Roaming', 'Fuyou-Chatroom')