#include <AesEncryptor.hpp>
#include <AesCyphers.hpp>
#include <AesModes.hpp>
#include <Reader.hpp>
#include <Writer.hpp>
#include <configReader.hpp>

int main(int argc, char* argv[])
{
  ConfigReader config(argc, argv);
  AesCypher256 default_c;
  AesModeEcb default_m;
  AesEncryptor encryptor(config, default_c, default_m);
  encryptor.encrypt();
  Reader reader;
  Writer Writer;
}
