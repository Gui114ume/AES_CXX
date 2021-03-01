#ifndef AesModeEcb_HPP 
#define AesModeEcb_HPP

#include <IAesEncryptionMode.hpp>
#include <IAesEncryptionCypher.hpp>
#include <configReader.hpp>

#include <iostream>

class AesModeEcb : public IAesEncryptionMode
{
public:
  AesModeEcb();
  virtual ~AesModeEcb() ;
  virtual void say_name() override;
  virtual void apply(IAesEncryptionCypher& cypher, ConfigReader& config) override;
};

#endif 