import json
import os
from basic.app_paths import AppPaths

class Config:
    @staticmethod
    def file_path():
        return os.path.join(os.getcwd(), 'config.json')
    

    @staticmethod
    def process_path(path: str):
        res = path.replace('${AppCachePath}', AppPaths.CACHE)
        return os.path.normpath(res)
    

    def get(self, key):
        val = self.__cfg.get(key)
        if val:
            return val
        else:
            raise ConfigCorruptedError()
    

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


config = Config()