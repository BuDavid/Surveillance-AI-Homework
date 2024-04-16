cmake_minimum_required(VERSION 3.0)
project(OpenCV_Image_Processing)# Find OpenCV package
find_package(OpenCV REQUIRED)# Include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})# Add the executable
add_executable(main main.cpp)# Link OpenCV libraries
target_link_libraries(main ${OpenCV_LIBS})
