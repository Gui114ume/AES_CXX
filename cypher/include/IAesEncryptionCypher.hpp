#ifndef IAesEncryptionCypher_HPP
#define IAesEncryptionCypher_HPP

#include <configReader.hpp>
#include <AesTypes.hpp>

class IAesEncryptionCypher
{
protected:
  IAesEncryptionCypher(){};
public:
  virtual void say_name() = 0;
  virtual void getKey() = 0;
  virtual chunk_t& apply(chunk_t& chunk) = 0;
  virtual ~IAesEncryptionCypher() {};

private:
  virtual void make_key_sched() = 0;
  virtual void verify_key_size() = 0;

  virtual void set_Nb() = 0;
  virtual i32 get_Nb() = 0;

  virtual void set_Nk() = 0;
  virtual i32 get_Nk() = 0;

  virtual void set_Nr() = 0;
  virtual i32 get_Nr() = 0;
};

#endif