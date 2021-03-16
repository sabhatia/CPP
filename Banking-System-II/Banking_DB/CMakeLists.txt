cmake_minimum_required(VERSION 3.0.0)
set(This Banking_Libraries)

project(${This} VERSION 0.1.0)
project({This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(Bank_Account_Library Bank_Account)
add_library(${Bank_Account_Library} Bank_Account.cpp)

set(Banking_DB_Library Banking_DB)
add_library(${Banking_DB_Library} Banking_DB.cpp)

set (Banking_System_Library Banking_System)
add_library(${Banking_System_Library} Banking_System.cpp)
