#ifndef Writer_HPP 
#define Writer_HPP

#include <iostream>

#include <AesTypes.hpp>

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