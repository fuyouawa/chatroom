import sys
import asyncio
from PyQt6.QtWidgets import QApplication
from tools.logger import Logger
from forms.loginwin import LoginWin
from chatclient import ChatClient
from basic.config import Config

def load_config_failed(e):
    Logger.fatal(f'加载配置文件失败!\n原因:{e}')

cfg = Config.load().unwrap_or_else(load_config_failed)
host = cfg.get('host')
port = cfg.get('port')
if not host or not port:
    Logger.fatal('配置文件损坏!')

async def run_client():
    try:
        client = ChatClient(host, port)
        await client.start()
    except Exception as e:
        Logger.fatal(f'客户端与服务器之间的链接异常断开!\n原因:{e}')

asyncio.run(run_client)
app = QApplication(sys.argv)
win = LoginWin()
win.show() 
sys.exit(app.exec())