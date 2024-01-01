cmake_minimum_required(VERSION 3.0.0)
project(chatroom)

# Output path of the library
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# We need to enable debugging information.
SET(CMAKE_BUILD_TYPE "Debug") 
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb -fcoroutines")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

include_directories(${PROJECT_SOURCE_DIR}/server/include)
include_directories(${PROJECT_SOURCE_DIR}/server/include/basic)
include_directories(${PROJECT_SOURCE_DIR}/server/include/message)
include_directories(${PROJECT_SOURCE_DIR}/server/include/service)
include_directories(${PROJECT_SOURCE_DIR}/server/include/model)
include_directories(${PROJECT_SOURCE_DIR}/server/include/tools)

add_subdirectory(server)