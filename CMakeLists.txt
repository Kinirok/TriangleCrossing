cmake_minimum_required(VERSION 3.16)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(TriangleCrossing)

add_subdirectory(
        "${CMAKE_CURRENT_SOURCE_DIR}/googletest"
        "googletest"
)
add_subdirectory(
        src
        test
)

include_directories(lib/googletest/googletest/include)

add_executable(
        TriangleCrossing
        src/main.cpp
)
add_executable(
        Tests
        test/PointTests.cpp
        test/IntersectionTests.cpp
        test/TriangleTests.cpp
)
target_link_libraries(TriangleCrossing logics)
target_link_libraries(Tests gtest gtest_main logics)
enable_testing()
