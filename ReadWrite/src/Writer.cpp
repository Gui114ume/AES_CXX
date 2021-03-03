#include <Writer.hpp>

Writer::Writer()
{
    std::cout << "Writer Constructor"<< std::endl;
}

Writer::~Writer()
{
    std::cout << "Writer Destructor"<< std::endl;
}

void Writer::appendInFile(chunk_t& chunk)
{
    std::cout << "Writer::appendInFile()" << std::endl;
}