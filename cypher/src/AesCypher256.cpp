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

void AesCypher256::make_key_sched()
{
    std::cout << "AesCypher256::make_key_sched() not implemented" <<std::endl;
}

void AesCypher256::verify_key_size()
{
    std::cout << "AesCypher256::verify_key_size() not implemented" <<std::endl;
}

void AesCypher256::init_sbox()
{
    std::cout << "AesCypher256::init_sbox() not implemented" <<std::endl;
}

void AesCypher256::init_rcon()
{
    std::cout << "AesCypher256::init_rcon() not implemented" <<std::endl;
}

void AesCypher256::set_Nb()
{

}

void AesCypher256::get_Nb()
{

}

void AesCypher256::set_Nk()
{

}

void AesCypher256::get_Nk()
{

}

void AesCypher256::set_Nr()
{

}

void AesCypher256::get_Nr()
{

}