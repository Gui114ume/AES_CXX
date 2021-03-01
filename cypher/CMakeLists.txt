cmake_minimum_required(VERSION 3.15.0)

add_library(aesCypher
    src/AesCypher256.cpp)
target_include_directories(aesCypher PUBLIC include/)
add_library(AES_CXX::aesCypher ALIAS aesCypher)
