import asyncio
import struct
from basic.packet import PACKET_HEADER_SIZE, Packet
from service.chatservice import service

class ServerClosedError(Exception):
    def __init__(self) -> None:
        super().__init__('The server closed the link')

class ChatClient:
    def __init__(self, host, port) -> None:
        self.host = host
        self.port = port

    async def start(self):
        await self.connect_to_server()
        await self.receive_loop()

    async def connect_to_server(self):
        self.reader, self.writter = await asyncio.open_connection(self.host, self.port)

    async def receive_loop(self):
        while True:
            header_data = await self.reader.read(PACKET_HEADER_SIZE)
            if not header_data:
                raise ServerClosedError()
            total_size, msg_id = struct.unpack('!HH', header_data)
            data = await self.reader.read(total_size - PACKET_HEADER_SIZE)
            service.handle_receive(Packet(total_size, msg_id, data))
