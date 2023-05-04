cmake_minimum_required(VERSION 3.5)

project(ElectronicDevices LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ElectronicDevices main.cpp)

install(TARGETS ElectronicDevices
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
