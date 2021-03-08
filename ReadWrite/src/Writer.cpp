#include <Writer.hpp>

Writer::Writer(ConfigReader& config)
    : m_config{config}, m_out{openFile(config)}
{
    std::cout << "Writer Constructor"<< std::endl;
}

Writer::~Writer()
{
    get_out().close();
    std::cout << "Writer Destructor"<< std::endl;
}

void Writer::appendInFile(chunk_t& chunk)
{
    std::cout << "Writer::appendInFile()" << std::endl;
    std::cout << chunk.size << std::endl;
    get_out().write((char*)chunk.value, chunk.size);
}

std::ofstream& Writer::openFile(ConfigReader& config)
{
    std::cout << "Writer::openFile()" << std::endl;
    std::ofstream* out = new std::ofstream(config.output_filename(),  std::ios::out | std::ios::app | std::ios::binary);
    
    return *out;
}

std::ofstream& Writer::get_out()
{
    return m_out;
}