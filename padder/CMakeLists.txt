cmake_minimum_required(VERSION 3.15.0)

add_library(aesPadder
    src/pkcsPadder.cpp)
target_include_directories(aesPadder PUBLIC include/)
include_directories(aesPadder PUBLIC ../types/include/)
add_library(AES_CXX::aesPadder ALIAS aesPadder)
