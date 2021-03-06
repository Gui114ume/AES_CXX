#ifndef AesCypher256_HPP
#define AesCypher256_HPP

#include "IAesEncryptionCypher.hpp"

#include <iostream>

class AesCypher256 : public IAesEncryptionCypher
{
public:
  virtual ~AesCypher256();
  virtual void say_name() override;
  virtual chunk_t& apply(chunk_t& chunk) override;
  virtual void getKey(ConfigReader& config) override;
  AesCypher256();

private:
  int m_Nb;
  int m_Nk;
  int m_Nr;
  SBox_t m_sbox[256];
  rcon_t m_rcon[255];
  key_sched_t* m_key_tab;
  aes_key_t* m_key;

  virtual void make_key_sched() override;
  virtual void verify_key_size() override;
  virtual void init_sbox() override;
  virtual void init_rcon() override;

  virtual void set_Nb() override;
  virtual void get_Nb() override;

  virtual void set_Nk() override;
  virtual void get_Nk() override;

  virtual void set_Nr() override;
  virtual void get_Nr() override;
};

#endif