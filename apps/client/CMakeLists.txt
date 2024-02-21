set(CLIENT_NAME chatroom)

file(GLOB_RECURSE SOURCES "*.cpp" "*.cc")

add_executable(${CLIENT_NAME} WIN32 ${SOURCES} ${COMMON_SOURCES})

target_link_libraries(${CLIENT_NAME} PRIVATE libprotobuf)