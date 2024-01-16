set(CLIENT_NAME chatroom)

include_directories(${THIRD_PARTY_DIR}/imgui)
include_directories(${THIRD_PARTY_DIR}/imgui_ex)

aux_source_directory(${THIRD_PARTY_DIR}/imgui_ex IMGUI_SOURCES)

file(GLOB_RECURSE SOURCES "*.cpp" "*.cc")

add_executable(${CLIENT_NAME} WIN32 ${SOURCES} ${IMGUI_SOURCES} ${COMMON_SOURCES})

# set(WIN32_LIB user32 gdi32 winmm kernel32)

target_link_libraries(${CLIENT_NAME} PRIVATE libprotobuf Ws2_32)