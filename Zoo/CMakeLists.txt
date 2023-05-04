cmake_minimum_required(VERSION 3.5)

project(Zoo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Zoo main.cpp)

install(TARGETS Zoo
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
