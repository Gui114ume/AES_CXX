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

void Writer::openFile()
{
    std::cout << "Writer::openFile()" << std::endl;
}
