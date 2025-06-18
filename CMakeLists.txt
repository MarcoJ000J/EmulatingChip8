cmake_minimum_required(VERSION 3.15)
project(Emu)

set(CMAKE_CXX_STANDARD 17)

# Caminhos para SDL3
include_directories(${CMAKE_SOURCE_DIR}/SDL/include)
link_directories(${CMAKE_SOURCE_DIR}/SDL/lib)

add_executable(emu main.cpp)
target_link_libraries(emu SDL3)