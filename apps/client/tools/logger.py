from enum import Enum
import sys
from PyQt6.QtWidgets import QMessageBox

class Logger:
    class Level(Enum):
        INFO = 0
        WARNING = 1
        DEBUG = 2
        ERROR = 3
        FATAL = 4
    LEVEL_STR = ['提示', '警告', '调试', '错误', '致命错误']

    def __init__(self, lv: Level, text) -> None:
        self.lv = lv
        self.text = text

    def output(self, parent):
        self.__show_messagebox(parent)


    def __show_messagebox(self, parent):
        title = self.LEVEL_STR[self.lv.value]
        if self.lv == Logger.Level.INFO:
            QMessageBox.information(parent, title, self.text)
        elif self.lv == Logger.Level.DEBUG:
            QMessageBox.information(parent, title, self.text)
        elif self.lv == Logger.Level.WARNING:
            QMessageBox.warning(parent, title, self.text)
        elif self.lv == Logger.Level.ERROR:
            QMessageBox.critical(parent, title, self.text)
        elif self.lv == Logger.Level.FATAL:
            QMessageBox.critical(parent, title, self.text)

    @staticmethod
    def info(text, parent=None):
        Logger(Logger.Level.INFO, text).output(parent)

    @staticmethod
    def debug(text, parent=None):
        Logger(Logger.Level.DEBUG, text).output(parent)

    @staticmethod
    def warning(text, parent=None):
        Logger(Logger.Level.WARNING, text).output(parent)

    @staticmethod
    def error(text, parent=None):
        Logger(Logger.Level.ERROR, text).output(parent)

    @staticmethod
    def fatal(text, parent=None, exit_code=1):
        Logger(Logger.Level.FATAL, text).output(parent)
        sys.exit(exit_code)
        
