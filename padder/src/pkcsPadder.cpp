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
    u8 tmp[size];
    for(u32 i = 0 ; i < size ; i++)
        tmp[i] = size;
    memcpy(&chunk.value[chunk.size], tmp, COMPLETE_CHUNK - chunk.size);
    chunk.size = COMPLETE_CHUNK;
    std::cout << "pkcsPadder::pad() not implemented" << std::endl; // next thing to do
}