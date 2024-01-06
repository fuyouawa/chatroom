import json
import os
from tools.result import Result

class Config:
    __cfg = None

    @staticmethod
    def file_path():
        return os.path.join(os.getcwd(), 'config.json')
    
    @classmethod
    def load(cls)-> Result[dict, Exception]:
        try:
            if cls.__cfg is None or not isinstance(cls.__cfg, dict):
                with open(cls.file_path(), 'r') as f:
                    cls.__cfg = json.load(f)
                    if not isinstance(cls.__cfg, dict):
                        return Result(err=ConfigCorruptedError())
            return Result(ok=cls.__cfg)
        except Exception as e:
            return Result(err=e)
        

class ConfigCorruptedError(Exception):
    def __init__(self) -> None:
        super().__init__(f'Configuration file corruption: {Config.file_path()}')