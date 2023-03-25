cmake_minimum_required(VERSION 3.5)

project(Assignment__2_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Assignment__2_2 main.cpp Invoice.cpp Invoice.hpp)

install(TARGETS Assignment__2_2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
