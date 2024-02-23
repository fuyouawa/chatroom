SET(SERVER_NAME chat-server)

include_directories(.)
include_directories(./model)
include_directories(./service)
include_directories(./tools)

file(GLOB_RECURSE SOURCES "*.cpp" "*.cc")

add_executable(${SERVER_NAME} ${COMMON_SOURCES} ${SOURCES})

target_link_libraries(${SERVER_NAME} PRIVATE protobuf mysqlcppconn)
