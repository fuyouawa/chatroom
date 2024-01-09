import struct
from core.enum.message_id import MessageID

PACKET_HEADER_SIZE = 4

PACKET_MAX_TOTAL_SIZE = 4096

class PacketCorruptionError(Exception):
    def __init__(self) -> None:
        super().__init__('Packet corruption')

class Packet:
    def __init__(self, total_size: int, msg_id: MessageID, data) -> None:
        if not PACKET_HEADER_SIZE <= total_size <= PACKET_MAX_TOTAL_SIZE:
            raise PacketCorruptionError()
        self.total_size = total_size
        self.msg_id = msg_id
        self.data = data

    def pack(self) -> bytes:
        header = struct.pack('!HH', self.total_size, self.msg_id.value)
        return header + self.data