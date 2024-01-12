class Singleton:
    __instance = {}

    def __init__(self):
        pass

    @classmethod
    def instance(cls, *args, **kwargs):
        if cls not in Singleton.__instance:
            Singleton.__instance[cls] = cls(*args, **kwargs)
        return Singleton.__instance[cls]