cmake_minimum_required(VERSION 3.12.0)
project(Ell LANGUAGES CXX C)

include(../common/cmake-common.cmake)

add_executable(Ell src/main.cpp src/Ell.cpp)
deal_ii_setup_target(Ell)
