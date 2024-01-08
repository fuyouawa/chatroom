from service.chatclient import ChatClient
from basic.config import config

client_cfg = config.get('client')
ChatClient.HOST = client_cfg['host']
ChatClient.PORT = client_cfg['port']
