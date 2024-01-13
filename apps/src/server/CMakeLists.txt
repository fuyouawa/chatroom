SET(CMAKE_BUILD_TYPE "Debug") 
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb -fcoroutines")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

include_directories(${PROJECT_SOURCE_DIR}/apps/include/server)
include_directories(${PROJECT_SOURCE_DIR}/apps/include/server/service)
include_directories(${PROJECT_SOURCE_DIR}/apps/include/server/tools)
include_directories(${PROJECT_SOURCE_DIR}/apps/include/server/model)

aux_source_directory(. SRC_LIST)
aux_source_directory(./service SRC_LIST)
aux_source_directory(./model SRC_LIST)
aux_source_directory(./tools SRC_LIST)
aux_source_directory(../public SRC_LIST)
aux_source_directory(../public/core SRC_LIST)
aux_source_directory(../public/msgpb SRC_LIST)
aux_source_directory(../public/tools SRC_LIST)

add_executable(chat-server ${SRC_LIST})

target_link_libraries(chat-server protobuf mysqlcppconn)