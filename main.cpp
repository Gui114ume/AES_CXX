#include <AesEncryptor.hpp>
#include <AesCyphers.hpp>
#include <AesModes.hpp>
#include <Reader.hpp>
#include <Writer.hpp>
#include <configReader.hpp>

int main(int argc, char* argv[])
{
  ConfigReader config(argc, argv);
  AesEncryptor encryptor(config);
  encryptor.encrypt();
}