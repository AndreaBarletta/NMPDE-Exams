cmake_minimum_required(VERSION 3.12.0)
project(lab08 LANGUAGES CXX C)

include(../common/cmake-common.cmake)

add_executable(ex-01-exercise1 src/ex-01-exercise1.cpp src/Parab.cpp)
deal_ii_setup_target(ex-01-exercise1)