#include <pkcsPadder.hpp>

pkcsPadder::pkcsPadder()
{
    std::cout << "pkcsPadder constructor" << std::endl;
}

pkcsPadder::~pkcsPadder()
{
    std::cout << "pkcsPadder destructor" << std::endl;
}

void pkcsPadder::say_name()
{
    std::cout << "pkcsPadder" << std::endl;
}

void pkcsPadder::pad(chunk_t& chunk)
{
    u8 size = chunk.size;
    
    std::cout << "pkcsPadder::pad() not implemented" << std::endl;
}