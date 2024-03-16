cmake_minimum_required(VERSION 3.5...3.21 FATAL_ERROR)
project(chatroom)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(APP_DIR ${PROJECT_SOURCE_DIR}/apps)

# Output path of the library
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(THIRD_PARTY_PATH ${PROJECT_SOURCE_DIR}/third-party)

include_directories(${APP_DIR}/)
include_directories(${APP_DIR}/common/msgpb)

file(GLOB_RECURSE COMMON_SOURCES ${APP_DIR}/common/*.cc)


SET(CMAKE_BUILD_TYPE "Debug") 
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb -fcoroutines")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

add_subdirectory(apps)
add_subdirectory(third-party)