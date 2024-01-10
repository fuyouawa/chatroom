import asyncio
import struct
from core.struct.packet import PACKET_HEADER_SIZE, Packet
from service.chatservice import ChatService
from PyQt6.QtCore import QMutexLocker, QMutex
from core.design.singleton import Singleton
from tools.tipbox import TipBox

class ServerClosedError(Exception):
    def __init__(self) -> None:
        super().__init__('服务器关闭了链接')

class ChatClient(Singleton):
    HOST: str
    PORT: int

    def __init__(self) -> None:
        self.__is_closed = False

        self.__pending_functors = []
        self.__pending_mutex = QMutex()


    def start(self):
        async def start_loop():
            await self.__connect_to_server()
            await self.__receive_loop()
            await self.__writter.wait_closed()
        asyncio.run(start_loop())


    def set_logger_parent(self, parent):
        self.__logger_parent = parent


    def is_closed(self):
        return self.__is_closed


    def notify_close(self):
        self.queue_functor_in_loop(self.__close)


    def queue_functor_in_loop(self, functor):
        with QMutexLocker(self.__pending_mutex):
            self.__pending_functors.append(functor)
        self.__wakeup_pending()


    async def __close(self):
        try:
            if self.__is_closed: return
            if self.__writter:
                self.__writter.close()
                self.__wakeup_writter.close()
                await self.__writter.wait_closed()
                await self.__wakeup_writter.wait_closed()
                self.__is_closed = True
        except Exception as e:
            TipBox.fatal(f'关闭服务器链接时出现错误: {e}', self.__logger_parent)


    def __wakeup_pending(self):
        try:
            self.__wakeup_writter.write(b'wk')
        except Exception as e:
            TipBox.fatal(f'意外错误: {e}', self.__logger_parent)


    async def __connect_to_server(self):
        self.__wakeup_server = await asyncio.start_server(self.__pending_loop, '127.0.0.1', 0)
        wakeup_server_port = self.__wakeup_server.sockets[0].getsockname()[1]
        _, self.__wakeup_writter = await asyncio.open_connection('127.0.0.1', wakeup_server_port)
        self.__reader, self.__writter = await asyncio.open_connection(self.HOST, self.PORT)


    async def __receive_loop(self):
        try:
            while not self.__is_closed:
                header_data = await self.__reader.read(PACKET_HEADER_SIZE)
                if not header_data:
                    raise ServerClosedError()
                total_size, msg_id = struct.unpack('!HH', header_data)
                data = await self.__reader.read(total_size - PACKET_HEADER_SIZE)
                ChatService.instance().handle_receive(Packet(total_size, msg_id, data))
        except Exception as e:
            TipBox.fatal(f'接收服务器数据时出现错误: {e}', self.__logger_parent)


    async def __pending_loop(self, wakeup_reader: asyncio.StreamReader, _):
        while not self.__is_closed:
            await wakeup_reader.read(2)
            await self.__do_pending_functors()


    async def __do_pending_functors(self):
        with QMutexLocker(self.__pending_mutex):
            functors = self.__pending_functors.copy()
            self.__pending_functors.clear()

        for functor in functors:
            await functor()
