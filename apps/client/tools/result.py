from typing import TypeVar, Generic, Callable

T = TypeVar('T')
E = TypeVar('E')

class Result(Generic[T, E]):
    def __init__(self, ok: T|None=None, err: E|None=None) -> None:
        super().__init__()
        self.__ok = ok
        self.__err = err

    def is_ok(self):
        return self.__ok is not None
    
    def is_err(self):
        return self.__err is not None
    
    def ok(self):
        return self.__ok
    
    def err(self):
        return self.__err
    
    def unwrap(self):
        if self.__ok:
            return self.__ok
        else:
            raise ValueError(self.__err)
        
    def expect(self, errmsg):
        if self.__ok:
            return self.__ok
        else:
            raise ValueError(errmsg)
        
    def unwrap_or_else(self, op: Callable[[E], T]):
        if self.__ok:
            return self.__ok
        else:
            return op(self.__err)
        
    def unwrap_or(self, val: T):
        if self.__ok:
            return self.__ok
        else:
            return val
        
    def __str__(self) -> str:
        if self.__ok:
            return f"Value({self.__ok})"
        else:
            return f"Error({self.__err})"