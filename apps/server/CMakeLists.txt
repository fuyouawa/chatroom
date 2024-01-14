SET(SERVER_NAME chat-server)

SET(CMAKE_BUILD_TYPE "Debug") 
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb -fcoroutines")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

include_directories(.)
include_directories(./model)
include_directories(./service)
include_directories(./tools)

file(GLOB_RECURSE SOURCES "*.cpp" "*.cc")

add_executable(${SERVER_NAME} ${COMMON_SOURCES} ${SOURCES})

target_link_libraries(${SERVER_NAME} PRIVATE protobuf mysqlcppconn)