import os
import sys

class PathHelper:
    @classmethod
    def user_home(cls):
        if not hasattr(PathHelper, '__user_home'):
            cls.__user_home = os.path.expanduser('~')
        return cls.__user_home


    @classmethod
    def appdata_path(cls):
        if not hasattr(PathHelper, '__appdata_path'):
            cls.__appdata_path  = os.path.join(cls.user_home(), 'AppData')
        return cls.__appdata_path
    

    @classmethod
    def current_module_path(cls):
        if not hasattr(PathHelper, '__current_module_path'):
            cls.__current_module_path  = os.path.realpath(sys.argv[0])
        return cls.__current_module_path
    

    @classmethod
    def current_module_dir(cls):
        if not hasattr(PathHelper, '__current_module_dir'):
            cls.__current_module_dir  = os.path.dirname(cls.current_module_path())
        return cls.__current_module_dir
    

    @classmethod
    def path_in_cur_module_dir(cls, *paths):
        return os.path.join(cls.current_module_dir(), *paths)