file(GLOB_RECURSE COMMON_SRCS "./common/*.cpp" "./common/*.cc")

if(WIN32)
    add_subdirectory(client)
else()
    add_subdirectory(server)
endif()