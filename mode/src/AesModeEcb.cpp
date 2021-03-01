#include <AesModeEcb.hpp>

#include <Padders.hpp>
#include <Reader.hpp>
#include <Writer.hpp>

enum paddingMethod
{
  pkcs
};

std::map<std::string, paddingMethod> mapPaddingMethod;

void init_mapPaddingMethod(std::map<std::string, paddingMethod> map)
{
    mapPaddingMethod["pkcs"] = pkcs;
}
IPadder& make_padder(ConfigReader& config)
{
    switch (mapPaddingMethod[config.padding_method()])
    {
    case pkcs:
    {
        /* code */
        IPadder* pkcs = new pkcsPadder;
        return *pkcs;
    }
    default:
    {
        IPadder* pkcs = new pkcsPadder;
        return *pkcs;
    }
    }
};

AesModeEcb::AesModeEcb()
{
    std::cout << "AesModeEcb constructor" << std::endl;
}

AesModeEcb::~AesModeEcb()
{
    std::cout << "AesModeEcb destructor" << std::endl; 
}

void AesModeEcb::apply(IAesEncryptionCypher& cypher, ConfigReader& config)
{
    std::cout << "AesModeEcb::apply() not implemented" << std::endl;
    Reader reader;
    Writer writer;
    init_mapPaddingMethod(mapPaddingMethod);
    IPadder& padder = make_padder(config);
    while( nb = reader.readInputNext8Words() )
    {
        if(  nb= fullValue)
        {
            // classic
        }
        else if( nb < value )
        {
            // finish the block tha'ts all (no last block remain)
        }
        else
        {
            // finish current and the last block is remaining
        }
    }
    if( last_block_remain)
    {
        // treat last block (if "no" padding was needed or if padding was made of completing and new block)
    }
}

void AesModeEcb::say_name()
{
    std::cout << "AesModeEcb"<< std::endl;
}

