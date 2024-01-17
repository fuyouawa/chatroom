cmake_minimum_required(VERSION 3.5...3.21 FATAL_ERROR)
project(chatroom)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output path of the library
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(THIRD_PARTY_DIR ${PROJECT_SOURCE_DIR}/third-party)

if(WIN32)
    include_directories($ENV{CXX_PACKETS_INCLUDE_PATH})
    link_directories($ENV{CXX_PACKETS_LIB_PATH})
endif()

include_directories(${THIRD_PARTY_DIR})
include_directories(${PROJECT_SOURCE_DIR}/apps)
include_directories(${PROJECT_SOURCE_DIR}/apps/common)
include_directories(${PROJECT_SOURCE_DIR}/apps/common/core)
include_directories(${PROJECT_SOURCE_DIR}/apps/common/msgpb)
include_directories(${PROJECT_SOURCE_DIR}/apps/common/tools)

add_subdirectory(apps)