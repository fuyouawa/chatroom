cmake_minimum_required(VERSION 3.0.0)
project(chatroom)

SET(CMAKE_BUILD_TYPE "Debug") 
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb -fcoroutines")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# Output path of the library
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/public)
include_directories(${PROJECT_SOURCE_DIR}/include/public/core)
include_directories(${PROJECT_SOURCE_DIR}/include/public/msgpb)
include_directories(${PROJECT_SOURCE_DIR}/include/public/tools)
include_directories(${PROJECT_SOURCE_DIR}/include/server)
include_directories(${PROJECT_SOURCE_DIR}/include/server/service)
include_directories(${PROJECT_SOURCE_DIR}/include/server/tools)
include_directories(${PROJECT_SOURCE_DIR}/include/server/model)

add_subdirectory(src)