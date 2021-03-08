#ifndef AesCypher128_HPP
#define AesCypher128_HPP

#include "IAesEncryptionCypher.hpp"

#include <iostream>

class AesCypher128 : public IAesEncryptionCypher
{
public:
  virtual ~AesCypher128();
  virtual void say_name() override;
  virtual chunk_t& apply(chunk_t& chunk) override;
  virtual void getKey() override;
  AesCypher128(ConfigReader& config);

private:
  ConfigReader& m_config;

  i32 m_Nb;
  i32 m_Nk;
  i32 m_Nr;
  key_sched_t* m_key_tab;
  aes_key_t* m_key;

  virtual void make_key_sched() override;
  virtual void verify_key_size() override;

  virtual void set_Nb() override;
  virtual i32 get_Nb() override;

  virtual void set_Nk() override;
  virtual i32 get_Nk() override;

  virtual void set_Nr() override;
  virtual i32 get_Nr() override;
};

#endif