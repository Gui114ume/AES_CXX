#include <Reader.hpp>

Reader::Reader()
{
    std::cout << "Reader Constructor"<< std::endl;
}

Reader::~Reader()
{
    std::cout << "Reader Destructor"<< std::endl;
}

chunk_t& Reader::readNextChunk()
{
    std::cout << "Reader::readNextChunk()" << std::endl;
    chunk_t* chunk = new chunk_t;
    return *chunk;
}