import json
import os
from dataclasses import dataclass
from tools.logger import Logger

class Config:
    @dataclass
    class ClientConfig:
        host: str
        port: int


    @staticmethod
    def file_path():
        return os.path.join(os.getcwd(), 'config.json')
    

    def __init__(self) -> None:
        try:
            self.__load()
            self.__check()
        except Exception as e:
            Logger.fatal(f'加载配置文件失败!\n原因:{e}')

    def __check(self):
        self.client_config()

    def __load(self):
        with open(Config.file_path(), 'r') as f:
            self.__cfg = json.load(f)
            if not isinstance(self.__cfg, dict):
                raise ConfigCorruptedError()

    def client_config(self):
        cfg = self.__cfg['client']
        return Config.ClientConfig(cfg['host'], cfg['port'])



class ConfigCorruptedError(Exception):
    def __init__(self) -> None:
        super().__init__(f'Configuration file corruption: {Config.file_path()}')

config = Config()