SET(SERVER_NAME chat-server)

include_directories(.)

file(GLOB_RECURSE SOURCES "*.cc")

add_executable(${SERVER_NAME} ${COMMON_SOURCES} ${SOURCES})

target_link_libraries(${SERVER_NAME} PRIVATE protobuf mysqlcppconn)
