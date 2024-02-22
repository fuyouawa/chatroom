set(CLIENT_NAME chatroom)

file(GLOB_RECURSE SOURCES "*.cpp" "*.cc")

include_directories(.)

add_executable(${CLIENT_NAME} ${SOURCES} ${COMMON_SOURCES})

target_compile_definitions(${CLIENT_NAME} PRIVATE _WIN32_WINNT=0x0A00)
target_link_libraries(${CLIENT_NAME} PRIVATE libprotobuf)