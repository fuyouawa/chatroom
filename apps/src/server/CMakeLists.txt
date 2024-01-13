aux_source_directory(. SRC_LIST)
aux_source_directory(./service SRC_LIST)
aux_source_directory(./model SRC_LIST)
aux_source_directory(./tools SRC_LIST)
aux_source_directory(../public SRC_LIST)
aux_source_directory(../public/core SRC_LIST)
aux_source_directory(../public/msgpb SRC_LIST)
aux_source_directory(../public/tools SRC_LIST)

add_executable(chat-server ${SRC_LIST})

target_link_libraries(chat-server protobuf mysqlcppconn)