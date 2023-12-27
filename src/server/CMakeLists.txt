aux_source_directory(. SRC_LIST)
aux_source_directory(./base SRC_LIST)
aux_source_directory(./model SRC_LIST)
aux_source_directory(./utils SRC_LIST)
aux_source_directory(../ SRC_LIST)
aux_source_directory(../message SRC_LIST)
aux_source_directory(../tools SRC_LIST)

add_executable(chat-server ${SRC_LIST})

target_link_libraries(chat-server protobuf mysqlcppconn mysqlclient)
