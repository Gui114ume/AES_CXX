#ifndef AesCypher256_HPP
#define AesCypher256_HPP

#include "IAesEncryptionCypher.hpp"

#include <iostream>

class AesCypher256 : public IAesEncryptionCypher
{
public:
  virtual ~AesCypher256();
  virtual void say_name() override;
  AesCypher256();
private:
};


#endif