import hashlib

def search_in_file(file_path, search_string):
    with open(file_path, 'rb') as file:
        file.seek(0, 2)
        file_size = file.tell()
        buffer_size = 4096
        current_pos = min(file_size, buffer_size)
        while current_pos > 0:
            file.seek(current_pos)
            buffer = file.read(buffer_size)
            position = buffer.rfind(search_string.encode())
            if position != -1:
                return current_pos + position
            current_pos -= buffer_size
        return None


def save_data_with_checksum(filename, data):
    checksum = hashlib.sha256(data).digest()
    with open(filename, 'wb') as file:
        file.write(checksum)
        file.write(data)


def read_data_with_checksum(filename):
    with open(filename, 'rb') as file:
        checksum = file.read(32)
        data = file.read()
    computed_checksum = hashlib.sha256(data).digest()
    if checksum == computed_checksum:
        return data
    else:
        return None