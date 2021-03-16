cmake_minimum_required(VERSION 3.0.0)
set(This Banking_Libraries)

project(${This} VERSION 0.1.0)
project({This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_executable(Bank_Account_Test Bank_Account_Test.cpp)
add_executable(Banking_DB_Test Banking_DB_Test.cpp)
