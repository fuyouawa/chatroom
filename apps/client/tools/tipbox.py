from enum import Enum
from PyQt6.QtWidgets import QMessageBox

class TipBox:
    class Level(Enum):
        INFO = 0
        WARNING = 1
        ERROR = 3
        FATAL = 4

    LEVEL_STR = ['提示', '警告', '错误', '致命错误']

    def __init__(self, lv: Level, text, parent=None) -> None:
        self.__lv = lv
        self.__text = text
        self.__parent = parent


    def show(self, save=False):
        self.__get_messagebox_call()()


    def __get_title(self):
        return self.LEVEL_STR[self.__lv.value]
    

    def __get_messagebox_call(self):
        title = self.__get_title()
        return {
            TipBox.Level.INFO: lambda: QMessageBox.information(self.__parent, title, self.__text),
            TipBox.Level.WARNING: lambda: QMessageBox.warning(self.__parent, title, self.__text),
            TipBox.Level.ERROR: lambda: QMessageBox.critical(self.__parent, title, self.__text),
            TipBox.Level.FATAL: lambda: QMessageBox.warning(self.__parent, title, self.__text),
        }.get(self.__lv)