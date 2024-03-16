set(CLIENT_NAME chatroom)

file(GLOB_RECURSE SOURCES "*.cc")

include_directories(.)
include_directories(${THIRD_PARTY_PATH}/yudb/include)

add_executable(${CLIENT_NAME} ${SOURCES} ${COMMON_SOURCES})

target_link_libraries(${CLIENT_NAME} PRIVATE protobuf yudb)