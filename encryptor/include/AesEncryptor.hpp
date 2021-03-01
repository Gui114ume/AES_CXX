#ifndef AesEncrypto_HPP
#define AesEncrypto_HPP

#include <AesCyphers.hpp>
#include <AesModes.hpp>
#include <configReader.hpp>

#include <map>
#include <string>

class AesEncryptor
{
private:
    /* data */
    IAesEncryptionCypher& m_cypher;
    IAesEncryptionMode& m_mode;
    ConfigReader& m_config;

    /* method */
    void set_config(ConfigReader& config);
    ConfigReader& get_config(void) const;

    void set_cypher(IAesEncryptionCypher& cypher);
    IAesEncryptionCypher& get_cypher(void) const;

    void set_mode(IAesEncryptionMode& mode);
    IAesEncryptionMode& get_mode(void) const;

    IAesEncryptionCypher& make_cypher(ConfigReader& config);
    IAesEncryptionMode& make_mode(ConfigReader& config);
public:
    AesEncryptor(ConfigReader& config, IAesEncryptionCypher& cypher, IAesEncryptionMode& mode);
    int encrypt();
    ~AesEncryptor();
};

#endif