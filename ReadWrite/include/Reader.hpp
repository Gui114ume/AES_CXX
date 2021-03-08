#ifndef Reader_HPP
#define Reader_HPP

#include <iostream>
#include <fstream>

#include <configReader.hpp>
#include <AesTypes.hpp>

class Reader
{
private:
    std::ifstream& m_in;
    ConfigReader& m_config;

    std::ifstream& get_in();
public:
    Reader(ConfigReader& config);
    ~Reader();
    std::ifstream& openFile(ConfigReader& config);
    chunk_t& readNextChunk();
};

#endif 
