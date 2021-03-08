#include <Reader.hpp>

Reader::Reader(ConfigReader& config)
: m_config{config}, m_in{openFile(config)}
{
    std::cout << "Reader Constructor"<< std::endl;
}

Reader::~Reader()
{
    get_in().close();
    std::cout << "Reader Destructor"<< std::endl;
}

chunk_t& Reader::readNextChunk()
{
    chunk_t* chunk = new chunk_t;
    get_in().read((char*)(chunk->value), COMPLETE_CHUNK);
    chunk->size = get_in().gcount();
    //std::cout << chunk->size << std::endl;
    //std::cout << get_in().gcount() << std::endl;
    return *chunk;
}

std::ifstream& Reader::openFile(ConfigReader& config)
{
    std::ifstream* in = new std::ifstream(config.input_filename(), std::ios::in | std::ios::binary);
    std::cout << "Reader::openFile()" << std::endl;
    return *in;
}

std::ifstream& Reader::get_in()
{
    return m_in;
}