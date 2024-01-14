cmake_minimum_required(VERSION 3.5...3.21 FATAL_ERROR)
project(chatroom)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Output path of the library
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(./apps)
include_directories(./apps/common)
include_directories(./apps/common/core)
include_directories(./apps/common/msgpb)
include_directories(./apps/common/tools)

add_subdirectory(apps)