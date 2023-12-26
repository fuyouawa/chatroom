aux_source_directory(. SRC_LIST)
aux_source_directory(../message SRC_LIST)
aux_source_directory(../ SRC_LIST)
aux_source_directory(../tools SRC_LIST)

add_executable(chat-client ${SRC_LIST})

target_link_libraries(chat-client protobuf)