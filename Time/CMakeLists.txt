cmake_minimum_required(VERSION 3.5)

project(Time LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Time main.cpp)

install(TARGETS Time
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
