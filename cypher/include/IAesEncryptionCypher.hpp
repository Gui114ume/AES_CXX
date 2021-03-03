#ifndef IAesEncryptionCypher_HPP
#define IAesEncryptionCypher_HPP

#include <configReader.hpp>

#ifndef CHUNK_DEF
#define CHUNK_DEF

#define COMPLETE_CHUNK 16 // bytes

typedef unsigned char byte;

typedef struct chunk_s
{
    byte part[16];
    unsigned size;
} chunk_t;

#endif

class IAesEncryptionCypher
{
protected:
  IAesEncryptionCypher(){};
public:
  virtual void say_name() = 0;
  virtual void getKey(ConfigReader& config) = 0;
  virtual chunk_t& apply(chunk_t& chunk) = 0;
  virtual ~IAesEncryptionCypher() {};
};

#endif