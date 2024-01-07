import asyncio
import struct
from basic.packet import PACKET_HEADER_SIZE, Packet
from service.chatservice import service
from basic.config import config
from PyQt6.QtCore import QMutexLocker, QMutex
from tools.logger import Logger

class ServerClosedError(Exception):
    def __init__(self) -> None:
        super().__init__('The server closed the link')

class ChatClient:
    def __init__(self) -> None:
        cfg = config.client_config()
        self.__host = cfg.host
        self.__port = cfg.port
        self.__is_closed = False

        self.__pending_functors = []
        self.__pending_mutex = QMutex()


    def start(self):
        async def start_loop():
            await self.__connect_to_server()
            await self.__receive_loop()
            await self.__writter.wait_closed()
        asyncio.run(start_loop())


    def is_closed(self):
        return self.__is_closed


    def notify_close(self):
        if self.__is_closed: return
        def close():
            if self.__writter:
                self.__writter.close()
            if self.__wakeup_writter:
                self.__wakeup_writter.close()
            self.__is_closed = True
        self.queue_functor_in_loop(close)


    def queue_functor_in_loop(self, functor):
        with QMutexLocker(self.__pending_mutex):
            self.__pending_functors.append(functor)
        self.__wakeup_pending()


    def __wakeup_pending(self):
        self.__wakeup_writter.write(b'wk')


    async def __connect_to_server(self):
        self.__wakeup_server = await asyncio.start_server(self.__pending_loop, '127.0.0.1', 0)
        wakeup_server_port = self.__wakeup_server.sockets[0].getsockname()[1]
        _, self.__wakeup_writter = await asyncio.open_connection('127.0.0.1', wakeup_server_port)
        self.__reader, self.__writter = await asyncio.open_connection(self.__host, self.__port)


    async def __receive_loop(self):
        while not self.__is_closed:
            header_data = await self.__reader.read(PACKET_HEADER_SIZE)
            if not header_data:
                raise ServerClosedError()
            total_size, msg_id = struct.unpack('!HH', header_data)
            data = await self.__reader.read(total_size - PACKET_HEADER_SIZE)
            service.handle_receive(Packet(total_size, msg_id, data))


    async def __pending_loop(self, wakeup_reader: asyncio.StreamReader, _):
        while not self.__is_closed:
            await wakeup_reader.read(2)
            await self.__do_pending_functors()


    async def __do_pending_functors(self):
        with QMutexLocker(self.__pending_mutex):
            functors = self.__pending_functors.copy()
            self.__pending_functors.clear()

        for functor in functors:
            functor()


chat_client = ChatClient()