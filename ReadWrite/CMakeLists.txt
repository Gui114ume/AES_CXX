cmake_minimum_required(VERSION 3.15.0)

add_library(aesReadWrite
    src/Writer.cpp
    src/Reader.cpp)
target_include_directories(aesReadWrite PUBLIC include/)
include_directories(aesReadWrite PUBLIC ../types/include/)
target_link_libraries(aesReadWrite PUBLIC AES_CXX::configReader)

add_library(AES_CXX::aesReadWrite ALIAS aesReadWrite)
