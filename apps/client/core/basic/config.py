import json
import os
from core.design.singleton import Singleton

class Config(Singleton):
    def __init__(self):
        self.__load()


    @staticmethod
    def file_path():
        return os.path.join(os.getcwd(), 'config.json')
    

    def __getitem__(self, key):
        return self.__cfg[key]
    

    def __init__(self) -> None:
        self.__load()


    def __load(self):
        with open(Config.file_path(), 'r') as f:
            self.__cfg = json.load(f)
            if not isinstance(self.__cfg, dict):
                raise ConfigCorruptedError()


class ConfigCorruptedError(Exception):
    def __init__(self) -> None:
        super().__init__(f'Configuration file corruption: {Config.file_path()}')
