#ifndef IAesEncryptionCypher_HPP
#define IAesEncryptionCypher_HPP

class IAesEncryptionCypher
{
protected:
  IAesEncryptionCypher(){};
public:
  virtual void say_name() = 0;
  virtual ~IAesEncryptionCypher() {};
};

#endif