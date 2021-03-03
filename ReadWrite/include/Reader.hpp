#ifndef Reader_HPP
#define Reader_HPP

#include <iostream>

#ifndef CHUNK_DEF
#define CHUNK_DEF

#define COMPLETE_CHUNK 16 // bytes

typedef unsigned char byte;

typedef struct chunk_s
{
    byte part[16];
    unsigned size;
} chunk_t;

#endif

class Reader
{
private:
    /* data */
public:
    Reader(/* args */);
    ~Reader();
    void openInputFile();
    chunk_t& readNextChunk();
};


#endif 
