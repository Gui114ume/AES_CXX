cmake_minimum_required(VERSION 3.15.0)

add_library(aesMode
    src/AesModeEcb.cpp)
target_include_directories(aesMode PUBLIC include/)
include_directories(aesMode PUBLIC ../types/include/)
target_link_libraries(aesMode PUBLIC AES_CXX::aesCypher)
target_link_libraries(aesMode PUBLIC AES_CXX::aesReadWrite)
target_link_libraries(aesMode PUBLIC AES_CXX::aesPadder)
target_link_libraries(aesMode PUBLIC AES_CXX::configReader)
add_library(AES_CXX::aesMode ALIAS aesMode)
