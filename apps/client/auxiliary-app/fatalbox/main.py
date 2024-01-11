from forms.fatalbox import FatalBox

import sys
from PyQt6.QtWidgets import QApplication
from forms.fatalbox import FatalBox

app = QApplication(sys.argv)

box = FatalBox(sys.argv[1], sys.argv[2], sys.argv[3])
box.show()

sys.exit(app.exec())