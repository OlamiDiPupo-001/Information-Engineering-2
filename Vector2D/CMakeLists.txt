cmake_minimum_required(VERSION 3.5)

project(Vector2D LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Vector2D main.cpp)

install(TARGETS Vector2D
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
