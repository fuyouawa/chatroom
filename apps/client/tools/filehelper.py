import os

class FileHelper:
    @classmethod
    def user_home(cls):
        if not hasattr(FileHelper, '__user_home'):
            cls.__user_home = os.path.expanduser('~')
        return cls.__user_home


    @classmethod
    def appdata_path(cls):
        if not hasattr(FileHelper, '__appdata_path'):
            cls.__appdata_path  = os.path.join(cls.user_home(), 'AppData')
        return cls.__appdata_path
    