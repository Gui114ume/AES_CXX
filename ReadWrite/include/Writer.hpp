#ifndef Writer_HPP 
#define Writer_HPP

#include <iostream>
#include <fstream>

#include <configReader.hpp>
#include <AesTypes.hpp>

class Writer
{
private:
    std::ofstream& m_out;
    ConfigReader& m_config;

    std::ofstream& get_out();
public:
    Writer(ConfigReader& config);
    ~Writer();
    std::ofstream& openFile(ConfigReader& config);
    void appendInFile(chunk_t& chunk);
};


#endif 