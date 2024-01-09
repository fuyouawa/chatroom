from service.chatclient import ChatClient
from core.basic.config import Config

config = Config().instance()
client_cfg = config['client']
ChatClient.HOST = client_cfg['host']
ChatClient.PORT = client_cfg['port']
