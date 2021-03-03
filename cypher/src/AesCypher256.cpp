#include <AesCypher256.hpp>

AesCypher256::AesCypher256()
{
    std::cout << "AesCypher256 constructor" << std::endl; 
}

AesCypher256::~AesCypher256()
{
    std::cout << "AesCypher256 destructor" << std::endl; 
}

void AesCypher256::say_name()
{
    std::cout << "AesCypher256" << std::endl;
}

void AesCypher256::getKey(ConfigReader& config)
{
    std::cout << "AesCypher256::getKey() not implemented" <<std::endl;
}

chunk_t& AesCypher256::apply(chunk_t& chunk)
{
    std::cout << "AesCypher256::apply() not implemented" <<std::endl;
    return chunk;
}