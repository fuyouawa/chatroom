cmake_minimum_required(VERSION 3.0.0)
project(chatroom)

# Output path of the library
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(./include)
include_directories(./include/basic)
include_directories(./include/message)
include_directories(./include/service)
include_directories(./include/model)
include_directories(./include/tools)

add_subdirectory(src)