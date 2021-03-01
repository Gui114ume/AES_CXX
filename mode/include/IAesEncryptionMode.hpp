#ifndef IAesEncryptionMode_HPP 
#define IAesEncryptionMode_HPP

#include <configReader.hpp>
#include <IAesEncryptionCypher.hpp>

class IAesEncryptionMode
{
protected:
  IAesEncryptionMode(){};
public:
  virtual void say_name() = 0;
  virtual void apply(IAesEncryptionCypher& cypher, ConfigReader& config) = 0;
  virtual ~IAesEncryptionMode(){};
};

#endif