cmake_minimum_required(VERSION 3.5)

project(homework1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(homework1 main.cpp)

install(TARGETS homework1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
