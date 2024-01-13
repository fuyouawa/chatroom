cmake_minimum_required(VERSION 3.5...3.21 FATAL_ERROR)
project(chatroom)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Output path of the library
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/apps/include)
include_directories(${PROJECT_SOURCE_DIR}/apps/include/public)
include_directories(${PROJECT_SOURCE_DIR}/apps/include/public/core)
include_directories(${PROJECT_SOURCE_DIR}/apps/include/public/msgpb)
include_directories(${PROJECT_SOURCE_DIR}/apps/include/public/tools)

add_subdirectory(apps)