#ifndef Writer_HPP 
#define Writer_HPP

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

class Writer
{
private:
    /* data */
public:
    Writer(/* args */);
    ~Writer();
    void openFile();
    void appendInFile(chunk_t& chunk);
};


#endif 