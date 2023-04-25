cmake_minimum_required(VERSION 3.16)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(TriangleCrossing)

add_executable(TriangleCrossing main.cpp Point.h Triangle.h Triangle.cpp Intersection.h Intersection.cpp Line.h Line.cpp)
