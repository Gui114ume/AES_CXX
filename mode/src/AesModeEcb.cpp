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
    init_mapPaddingMethod(mapPaddingMethod);
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
    std::cout << "AesModeEcb::apply()" << std::endl;
    Reader reader(config);
    Writer writer(config);
    IPadder& padder = make_padder(config);
    unsigned nb_bytes_read = 0;
    chunk_t chunk;
    chunk_t encrypted_chunk;
    bool size_is_multiple_of_16_bytes = true;
    while( 1 )
     {
        chunk = reader.readNextChunk();
        if (!chunk.size)
            break;
        if (chunk.size == COMPLETE_CHUNK)
        {
            // complete CHUNK
            std::cout<<"complete CHUNK"<<std::endl;
            encrypted_chunk = cypher.apply(chunk);
            writer.appendInFile(encrypted_chunk);
        }
        else 
        {
            // incomplete CHUNK
            std::cout<<"incomplete CHUNK"<<std::endl;
            padder.pad(chunk);
            encrypted_chunk = cypher.apply(chunk);
            writer.appendInFile(encrypted_chunk);
            size_is_multiple_of_16_bytes = false;
        }
     }
     if(size_is_multiple_of_16_bytes)
        {
            std::cout<<"last chunk because the size(file) is multiple of 16 bytes"<<std::endl;
            padder.pad(chunk); // here, chunk.size is 0 necessarily
            encrypted_chunk = cypher.apply(chunk);
            writer.appendInFile(encrypted_chunk);
        }
}

void AesModeEcb::say_name()
{
    std::cout << "AesModeEcb"<< std::endl;
}

