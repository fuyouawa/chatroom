class Logger:
    SAVE_PATH: str

    @classmethod
    def save_log(cls, text):
        with open(cls.SAVE_PATH, 'a') as f:
            f.write(text)