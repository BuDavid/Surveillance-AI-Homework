cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(hello VERSION 1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(sort_app ${SRC_FILES})
target_include_directories(sort_app PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

