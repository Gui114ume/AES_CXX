#ifndef configReader_HPP
#define configReader_HPP 

#include <boost/optional/optional.hpp>
#include <boost/program_options.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/range/end.hpp>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sys/stat.h>

#include <configuration.hpp>

using std::cerr;
using std::cout;
using std::endl;
using std::exit;

namespace po = boost::program_options;
namespace pt = boost::property_tree;

class ConfigReader : public Configuration
{
  /// name of the input file used for inital conditions
  std::string m_input_filename;

  /// name of the output file used for backups
  std::string m_output_filename;

  /// name of the key file used for backups
  std::string m_key_filename;

  /// name of the padding method
  std::string m_padding_method;

  /// name of the AES cipher
  std::string m_cypher_type;

  /// name of the encryption mode
  std::string m_encryption_mode;
  
  /** init the boost options
   *  @param options description of the options
   */
  void init_options(po::options_description &options) const;

  /** print the help message if necessary
   *  @param vm the map of variables
   *  @param options the options description
   */
  void print_help(const po::variables_map &vm,
                  const po::options_description &options) const;

  /** print the help message if necessary
   *  @param vm the map of variables to fill
   *  @param options the options description
   *  @param argc the number of arguments given to the program
   *  @param argv the arguments given to the program
   */
  void parse_arguments(po::variables_map &vm,
                       const po::options_description &options, const int argc,
                       const char *const argv[]) const;

  /** set the parameters from the command line
   *  @param vm the map of variables
   */
  void set_commmand_line(const po::variables_map &vm);

  /** set the parameters from the config file
   *  @param std::string name of the config file
   */
  void set_config_file(const std::string &filename);

  /** print the config file if necessary
   *  @param vm the map of variables
   */
  void print_config(const po::variables_map &vm) const;

  /** check if the parameters are correct
   *  @param vm the map of variables
   */
  void check_config() const;

public:
  /** Construct a new ConfigReader and intialize the configuration from the
   * command line or from the configuration file
   * @param argc the number of command-line arguments
   * @param argv the values of command-line arguments
   */
  ConfigReader(const int argc, const char *const argv[]);

  // see overridden function
  std::string input_filename() const override { return m_input_filename; }

  // see overridden function
  std::string output_filename() const override { return m_output_filename; }

  // see overridden function
  std::string key_filename() const override { return m_key_filename; }

  // see overridden function
  std::string encryption_mode() const override { return m_encryption_mode; }

  // see overridden function
  std::string cypher_type() const override {return m_cypher_type; }

  // see overriden function
  std::string padding_method() const override {return m_padding_method; }
};

#endif