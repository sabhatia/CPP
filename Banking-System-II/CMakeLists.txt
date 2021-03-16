cmake_minimum_required(VERSION 3.0.0)
set(This Banking_System_II)

project(${This} VERSION 0.1.0)
project({This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(Banking_DB)
add_subdirectory(Banking_System_Test)


add_executable(${This} Banking_System_UI.cpp)

