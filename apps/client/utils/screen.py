from PyQt6.QtWidgets import QApplication, QWidget
from PyQt6.QtCore import QPoint


class ScreenUtil:
    @staticmethod
    def central_point(widget: QWidget):
        rect = QApplication.primaryScreen().geometry()
        return rect.center() - QPoint(widget.width() // 2, widget.height() // 2)