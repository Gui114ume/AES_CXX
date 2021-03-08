cmake_minimum_required(VERSION 3.15.0)

add_library(configReader 
    src/configReader.cpp)
target_include_directories(configReader PUBLIC include/)
add_library(AES_CXX::configReader ALIAS configReader)
