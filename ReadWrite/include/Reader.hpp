#ifndef Reader_HPP
#define Reader_HPP

#include <iostream>

class Reader
{
private:
    /* data */
public:
    Reader(/* args */);
    ~Reader();
    void openKeyFile();
    void getKey();
    void openInputFile();
    void readInputNext8Words();
};


#endif 
