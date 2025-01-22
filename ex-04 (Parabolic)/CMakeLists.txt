cmake_minimum_required(VERSION 3.12.0)
project(Parab LANGUAGES CXX C)

include(../common/cmake-common.cmake)

add_executable(Parab src/main.cpp src/Parab.cpp)
deal_ii_setup_target(Parab)
