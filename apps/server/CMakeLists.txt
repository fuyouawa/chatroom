cmake_minimum_required(VERSION 3.5...3.21 FATAL_ERROR)
project(chatroom)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_DIR ..)
set(APP_DIR ..)

# Output path of the library
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_DIR}/bin)

include_directories(${THIRD_PARTY_DIR})
include_directories(${APP_DIR}/)
include_directories(${APP_DIR}/common)
include_directories(${APP_DIR}/common/core)
include_directories(${APP_DIR}/common/msgpb)
include_directories(${APP_DIR}/common/tools)

file(GLOB_RECURSE COMMON_SOURCES ${APP_DIR}/common/*.cpp ${APP_DIR}/common/*.cc)

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