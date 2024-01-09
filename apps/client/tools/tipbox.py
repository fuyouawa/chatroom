from enum import Enum
from PyQt6.QtWidgets import QMessageBox
from datetime import datetime

class TipBox:
    class Level(Enum):
        INFO = 0
        WARNING = 1
        ERROR = 3
        FATAL = 4

    SAVE_PATH: str
    LEVEL_STR = ['提示', '警告', '错误', '致命错误']

    def __init__(self, lv: Level, text, parent=None) -> None:
        self.__lv = lv
        self.__text = text
        self.__parent = parent


    def show(self, save=False):
        self.__show_messagebox()
        if save:
            self.__save_to_file()


    def __get_title(self):
        return self.LEVEL_STR[self.__lv.value]
    

    def __show_messagebox(self):
        title = self.__get_title()
        call = {
            TipBox.Level.INFO: lambda: QMessageBox.information(self.__parent, title, self.__text),
            TipBox.Level.WARNING: lambda: QMessageBox.warning(self.__parent, title, self.__text),
            TipBox.Level.ERROR: lambda: QMessageBox.critical(self.__parent, title, self.__text),
            TipBox.Level.FATAL: lambda: QMessageBox.warning(self.__parent, title, self.__text),
        }.get(self.__lv)
        return call()
    

    def __save_to_file(self):
        title = self.__get_title()
        with open(self.SAVE_PATH, 'a') as f:
            fmt_time = datetime.now().strftime('%Y/%m/%d %H:%M:%S')
            f.write(f'({fmt_time})[{title}]')


    @staticmethod
    def info(text, parent=None):
        TipBox(TipBox.Level.INFO, text, parent).show()


    @staticmethod
    def warning(text, parent=None):
        TipBox(TipBox.Level.WARNING, text, parent).show()


    @staticmethod
    def error(text, parent=None):
        TipBox(TipBox.Level.ERROR, text, parent).show(save=True)


    @staticmethod
    def fatal(text, parent=None):
        TipBox(TipBox.Level.FATAL, text, parent).show(save=True)