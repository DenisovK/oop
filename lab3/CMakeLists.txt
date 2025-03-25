cmake_minimum_required(VERSION 3.10)
project(Figures)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(Figures src/main.cpp src/Rectangle.cpp src/Trapezoid.cpp src/Rhombus.cpp)