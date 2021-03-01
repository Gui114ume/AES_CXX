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