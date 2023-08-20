cmake_minimum_required(VERSION 3.2)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

project(HW-dpcpp-1.3)

add_library(AdvancedSqlSelectQueryBuilder AdvancedSqlSelectQueryBuilder.hpp AdvancedSqlSelectQueryBuilder.cpp)

add_library(SqlSelectQueryBuilder SHARED SqlSelectQueryBuilder.hpp SqlSelectQueryBuilder.cpp)

add_executable(HW-dpcpp-1.3 main.cpp)

target_link_libraries(SqlSelectQueryBuilder PUBLIC AdvancedSqlSelectQueryBuilder)

target_link_libraries(HW-dpcpp-1.3 SqlSelectQueryBuilder)
