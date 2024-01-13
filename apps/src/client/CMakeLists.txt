find_package(Qt6 COMPONENTS Widgets REQUIRED)

aux_source_directory(. SRC_LIST)
add_executable(chatroom ${SRC_LIST})

target_link_libraries(chatroom PRIVATE Qt6::Widgets)
