cmake_minimum_required(VERSION 3.0.0)
set(This Banking_Libraries)

project(${This} VERSION 0.1.0)
project({This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_executable(Banking_DB_Test Banking_DB_Test.cpp)

add_executable(GT_Bank_Account GT_Bank_Account.cpp)
target_link_libraries(GT_Bank_Account PUBLIC
    gtest_main
    Bank_Account)
    
add_test(
    NAME GT_Bank_Account
    COMMAND GT_Bank_Account
)

add_executable(GT_Banking_DB GT_Banking_DB.cpp)
target_link_libraries(GT_Banking_DB PUBLIC
    gtest_main
    Banking_DB)
    
add_test(
    NAME GT_Banking_DB
    COMMAND GT_Banking_DB
)
