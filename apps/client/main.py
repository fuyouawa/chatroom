import sys
import asyncio
from PyQt6.QtWidgets import QApplication
from tools.logger import Logger
from forms.loginwin import LoginWin
from chatclient import ChatClient
from basic.config import config


async def run_client():
    try:
        cfg = config.client_config()
        client = ChatClient(cfg.host, cfg.port)
        await client.start()
    except Exception as e:
        Logger.fatal(f'客户端与服务器之间的链接异常断开!\n原因:{e}')


asyncio.run(run_client())
# app = QApplication(sys.argv)
# win = LoginWin()
# win.show()
# sys.exit(app.exec())