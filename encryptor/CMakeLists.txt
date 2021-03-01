cmake_minimum_required(VERSION 3.15.0)

add_library(aesEncryptor
    src/AesEncryptor.cpp)
target_include_directories(aesEncryptor PUBLIC include/)
target_link_libraries(aesEncryptor PUBLIC AES_CXX::configReader)
target_link_libraries(aesEncryptor PUBLIC AES_CXX::aesCypher)
target_link_libraries(aesEncryptor PUBLIC AES_CXX::aesMode)
add_library(AES_CXX::aesEncryptor ALIAS aesEncryptor)
