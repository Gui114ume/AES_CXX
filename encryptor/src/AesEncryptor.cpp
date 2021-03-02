#include <AesEncryptor.hpp>

enum cypherType
{
    aes128,
    aes192,
    aes256
};

enum encryptionMode
{
    ECB,
    CBC
};

std::map<std::string, cypherType> mapCypherType;
std::map<std::string, encryptionMode> mapEncryptionMode;

void init_mapCypherType(std::map<std::string, cypherType> map)
{
    mapCypherType["aes128"] = aes128;
    mapCypherType["aes192"] = aes192;
    mapCypherType["aes256"] = aes256;
}

void init_mapEncryptionMode(std::map<std::string, encryptionMode> map)
{
    mapEncryptionMode["ECB"] = ECB;
    mapEncryptionMode["CBC"] = CBC;
}

void AesEncryptor::set_config(ConfigReader &config)
{
    m_config = config;
}

ConfigReader &AesEncryptor::get_config(void) const
{
    return m_config;
}

void AesEncryptor::set_cypher(IAesEncryptionCypher &cypher)
{
    m_cypher = cypher;
}
IAesEncryptionCypher &AesEncryptor::get_cypher(void) const
{
    return m_cypher;
}

void AesEncryptor::set_mode(IAesEncryptionMode &mode)
{
    m_mode = mode;
}
IAesEncryptionMode &AesEncryptor::get_mode(void) const
{
    return m_mode;
}

AesEncryptor::AesEncryptor(ConfigReader &config, IAesEncryptionCypher &cypher, IAesEncryptionMode &mode)
    : m_config{config}, m_cypher{cypher}, m_mode{mode}
{
    std::cout << "AesEncryptor constructor" << std::endl;
    init_mapCypherType(mapCypherType);
    init_mapEncryptionMode(mapEncryptionMode);
    set_cypher(make_cypher(m_config));
    set_mode(make_mode(m_config));
}

IAesEncryptionCypher &AesEncryptor::make_cypher(ConfigReader &config)
{
    switch (mapCypherType[config.cypher_type()])
    {
    case aes128:
    {
        /* code */
        std::cout << "aes128 not implemented, use aes256" << std::endl;
        AesCypher256* cypher256 = new AesCypher256;
        return *cypher256;
    }
    case aes192:
    {
        /* code */
        std::cout << "aes192 not implemented, use aes256" << std::endl;
        AesCypher256* cypher256 = new AesCypher256;
        return *cypher256;
    }
    case aes256:
    {
        /* code */
        std::cout << "aes256 not implemented" << std::endl;
        AesCypher256* cypher256 = new AesCypher256;
        return *cypher256;
    }
    default:
    {
        AesCypher256* cypher256 = new AesCypher256;
        return *cypher256;
    }
    }
}

IAesEncryptionMode &AesEncryptor::make_mode(ConfigReader &config)
{
    switch (mapEncryptionMode[config.encryption_mode()])
    {
    case ECB:
    {
        /* code */
        std::cout << "ECB mode not implemented" << std::endl;
        AesModeEcb* modeEcb = new AesModeEcb;
        return *modeEcb;
    }
    case CBC:
    {
        /* code */
        std::cout << "CBC mode not implemented, use ECB" << std::endl;
        AesModeEcb* modeEcb = new AesModeEcb;
        return *modeEcb;
    }
    default:
    {
        std::cout << "ECB mode not implemented" << std::endl;
        AesModeEcb* modeEcb = new AesModeEcb;
        return *modeEcb;
    }
    }
}

int AesEncryptor::encrypt()
{
    std::cout << "AesEncryptor::encrypt() not implemented" << std::endl;
    get_mode().apply(get_cypher(), get_config());
    return 1;
}

AesEncryptor::~AesEncryptor()
{
    std::cout << "AesEncryptor destructor" << std::endl;
}