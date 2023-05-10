cmake_minimum_required(VERSION 3.5)

project(rat_game_HW LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(rat_game_HW main.cpp)

install(TARGETS rat_game_HW
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
set(SFML_DIR "C:/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

target_link_libraries(rat_game_HW sfml-graphics sfml-audio)
target_include_directories(rat_game_HW PRIVATE "C:/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/include")
