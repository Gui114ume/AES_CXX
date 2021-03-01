cmake_minimum_required(VERSION 3.15.0)
project(AES_CXX C CXX)

find_package(Boost 1.56 REQUIRED COMPONENTS program_options)

add_subdirectory(configReader)
add_subdirectory(cypher)
add_subdirectory(mode)
add_subdirectory(padder)
add_subdirectory(encryptor)
add_subdirectory(ReadWrite)

add_executable(main
		main.cpp)
		
target_link_libraries(main PRIVATE
			   AES_CXX::configReader
			   AES_CXX::aesEncryptor
			   AES_CXX::aesCypher
			   AES_CXX::aesMode
			   AES_CXX::aesPadder
			   AES_CXX::aesReadWrite
			   Boost::program_options)
