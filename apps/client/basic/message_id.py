from enum import Enum

class MessageID(Enum):
    USER_REGISTER = 0
    USER_REGISTER_ACK = 1
    USER_LOGIN = 2
    USER_LOGIN_ACK = 3
    USER_FORCE_OFFLINE = 4