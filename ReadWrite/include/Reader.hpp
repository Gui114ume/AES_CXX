#ifndef Reader_HPP
#define Reader_HPP

#include <iostream>

#include <AesTypes.hpp>

class Reader
{
private:
    /* data */
public:
    Reader(/* args */);
    ~Reader();
    void openFile();
    chunk_t& readNextChunk();
};

#endif 
