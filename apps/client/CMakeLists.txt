set(CLIENT_NAME chatroom)

include_directories(${THIRD_PARTY_DIR}/imgui)
include_directories(${THIRD_PARTY_DIR}/imgui_ex)

# file(GLOB_RECURSE IMGUI_SOURCES ${THIRD_PARTY_DIR}/imgui/*.cpp ${THIRD_PARTY_DIR}/imgui_ex/*.cpp)
file(GLOB_RECURSE SOURCES "*.cpp" "*.cc")

add_executable(${CLIENT_NAME} ${COMMON_SOURCES} ${SOURCES} ${IMGUI_SOURCES})

target_link_libraries(${CLIENT_NAME} PRIVATE libprotobuf Ws2_32)