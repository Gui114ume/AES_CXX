#ifndef configuration_HPP
#define configuration_HPP

#include <string>
#include <array>

class Configuration
{
public:
  /// The destructor
  virtual ~Configuration() = default;

  /** Access the input filename
   * @return the input filename
   */
  virtual std::string input_filename() const = 0;

  /** Access the output filename
   * @return the output filename
   */
  virtual std::string output_filename() const = 0;

  /** Access the key filename
   * @return the key filename
   */
  virtual std::string key_filename() const = 0;

/** Access the encryption mode
   * @return the encryption mode
   */
  virtual std::string encryption_mode() const = 0;

/** Access the cypher type
   * @return the cypher type
   */
  virtual std::string cypher_type() const = 0;

  /** Access the padding method
   * @return the padding method
   */
  virtual std::string padding_method() const = 0;
};

#endif