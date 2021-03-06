cmake_minimum_required(VERSION 3.15.0)

add_library(aesCypher
    src/AesCypher256.cpp)
target_include_directories(aesCypher PUBLIC include/)
include_directories(aesCypher PUBLIC ../types/include/)
target_link_libraries(aesCypher PUBLIC AES_CXX::configReader)
add_library(AES_CXX::aesCypher ALIAS aesCypher)
