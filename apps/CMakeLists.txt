file(GLOB_RECURSE COMMON_SOURCES "./common/*.cpp" "./common/*.cc")

if(WIN32)
    add_subdirectory(client)
else()
    add_subdirectory(server)
endif()