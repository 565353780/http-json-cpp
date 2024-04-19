cmake_minimum_required(VERSION 3.17)
project(http_json_cpp)
set(CMAKE_CXX_FLAGS "-std=c++17 -O0")

set(ROOT_PATH ./http_json_cpp/Cpp)

set(SRC_PATH ${ROOT_PATH}/src)

include_directories(${ROOT_PATH}/include)

set(SRC ${SRC_PATH}/json_manager.cpp)

add_executable(${PROJECT_NAME} ${ROOT_PATH}/main.cpp ${SRC})
