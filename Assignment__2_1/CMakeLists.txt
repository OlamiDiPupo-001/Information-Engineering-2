cmake_minimum_required(VERSION 3.5)

project(Assignment__2_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Assignment__2_1 main.cpp Time.cpp Time.hpp)

install(TARGETS Assignment__2_1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
