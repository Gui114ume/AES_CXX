#include "configReader.hpp"
#include <string>

// test if a file exist
bool exist(const char *filename, struct stat *buffer)
{
  return stat(filename, buffer) == 0;
}

// print an error message if the rank of the processus is equal to zero
// and set error_code to 1
void alert(const std::string &to_print, int &error_code)
{
  error_code = 1;
  std::cerr << std::endl
            << "Fatal-error: " << to_print << std::endl
            << std::endl;
}

// print a warning message if the rank of the processus is equal to zero
void warning(const std::string &to_print)
{
  std::cerr << std::endl
            << "Warning: " << to_print << std::endl
            << std::endl;
}

// initialize the opition description
void ConfigReader::init_options(po::options_description &options) const
{
  // add the opttions description
  options.add_options()("config-file", po::value<std::string>(),
      "config-file name used to initialize the configuration (no default "
      "value)")(
      "input-file", po::value<std::string>(),
      "input-file name used for initial conditions (no default value)")(
      "output-file", po::value<std::string>(),
      "output-file used to save results (no default value)")(
      "key-file", po::value<std::string>(),
      "key-file used to encrypt/decrypt (no default value)")(
      "padding-method", po::value<std::string>()->default_value("pkcs"),
      "padding-method used to pad the file to encrypt (pkcs is the default value)")(
      "cypher-type", po::value<std::string>()->default_value("aes256"),
      "cypher-type used to encrypt file (aes256 is the default value)")(
      "encryption-mode", po::value<std::string>()->default_value("ECB"),
      "encryption-mode used to encrypt file (ECB default value)")(
      "help", "produce help message")("print-args,pa",
                                      "print the command-line arguments");
}

// print the option description if the rank of the processus is 0 and if the
// help argument is given to the program, and then quit the program
void ConfigReader::print_help(const po::variables_map &vm,
                              const po::options_description &options) const
{
  if (vm.count("help"))
  {
    std::cout << options << std::endl;
    exit(0);
  }
}

// parse the command line and fill the map of variables, if a string is detected
// without an argument prefix, this string will be the configuration file
void ConfigReader::parse_arguments(po::variables_map &vm,
                                   const po::options_description &options,
                                   const int argc,
                                   const char *const argv[]) const
{
  po::positional_options_description p;
  p.add("config-file", -1);

  po::store(
      po::command_line_parser(argc, argv).options(options).positional(p).run(),
      vm);
  po::notify(vm);
}

// set the member variables with the arguments given in the command line
void ConfigReader::set_commmand_line(const po::variables_map &vm)
{
  // set the parameters
  if (vm.count("input-file"))
    m_input_filename = vm["input-file"].as<std::string>();
  if (vm.count("output-file"))
    m_output_filename = vm["output-file"].as<std::string>();
  if (vm.count("key-file"))
    m_key_filename = vm["key-file"].as<std::string>();
  if (vm.count("padding-method"))
    m_padding_method = vm["padding-method"].as<std::string>();
  if (vm.count("encryption-mode"))
    m_encryption_mode = vm["encryption-mode"].as<std::string>();
  if (vm.count("cypher-type"))
    m_cypher_type = vm["cypher-type"].as<std::string>();
}

// set the member variables with the arguments given in the configuration file
void ConfigReader::set_config_file(const std::string &filename)
{
  // inform the user
  std::cout << std::endl;
  std::cout << "Information: When a config file is given, only the arguments "
               "of this";
  std::cout << "file are used, except for \"print-args\" and \"help\""
            << std::endl;
  std::cout << std::endl;

  // create the property tree
  pt::ptree tree;

  // parse the config file
  pt::read_xml(filename, tree);

  boost::optional<std::string> in_opt =
      tree.get_optional<std::string>("input-file");
  if (in_opt)
    m_input_filename = (*in_opt);

  boost::optional<std::string> out_opt =
      tree.get_optional<std::string>("output-file");
  if (out_opt)
    m_output_filename = (*out_opt);

  boost::optional<std::string> key_opt =
      tree.get_optional<std::string>("key-file");
  if (key_opt)
    m_key_filename = (*key_opt);

  boost::optional<std::string> padding_opt =
      tree.get_optional<std::string>("padding-method");
  if (padding_opt)
    m_padding_method = (*padding_opt);

  boost::optional<std::string> encryption_opt =
      tree.get_optional<std::string>("encryption-mode");
  if (encryption_opt)
    m_encryption_mode = (*encryption_opt);

  boost::optional<std::string> cypher_type_opt =
      tree.get_optional<std::string>("cypher-type");
  if (cypher_type_opt)
    m_cypher_type= (*cypher_type_opt);
}

// the processus print the current configuration on the standard
// output
void ConfigReader::print_config(const po::variables_map &vm) const
{
  if (vm.count("print-args"))
  {
    std::cout << "************** Configutation **************" << std::endl;
    if (!m_input_filename.empty())
      std::cout << "m_input_filename = " << m_input_filename << std::endl;
    if (!m_output_filename.empty())
      std::cout << "m_output_filename = " << m_output_filename << std::endl;
    if (!m_key_filename.empty())
      std::cout << "m_key_filename = " << m_key_filename << std::endl;
    if (!m_padding_method.empty())
      std::cout << "m_padding_method = " << m_padding_method << std::endl;
    if (!m_encryption_mode.empty())
      std::cout << "m_encryption_mode = " << m_encryption_mode << std::endl;
    if (!m_cypher_type.empty())
      std::cout << "m_cypher_type = " << m_cypher_type << std::endl;
    std::cout << "*******************************************" << std::endl;
    std::cout << std::endl;
  }
}

// check if the configuration is well defined
void ConfigReader::check_config() const
{
  int error_code = 0;

  struct stat buffer;

  if(m_input_filename.empty())
    alert("No input filename was given", error_code);

  if (!m_input_filename.empty() && !exist(m_input_filename.c_str(), &buffer))
    alert("The given input file cannot be found", error_code);

  if(m_output_filename.empty())
    alert("No output filename was given",error_code);
    
  if (!m_output_filename.empty() &&
          (exist(m_output_filename.c_str(), &buffer)) ||
      exist(("mean_" + m_output_filename).c_str(), &buffer))
    alert("The given output file already exist, please remove it or change the "
          "filename",
          error_code);

  if (m_key_filename.empty())
    alert("No key filename was given", error_code);

  if (m_padding_method.empty())
    alert("No padding method was given", error_code);

  if (m_cypher_type.empty())
    alert("No cypher type was given", error_code);

  if(m_encryption_mode.empty())
    alert("No encryption mode was given", error_code);

  if (error_code != 0)
  {
    exit(error_code);
  }
}

// initialize the configuration from the command line or from the configuration
// file
ConfigReader::ConfigReader(const int argc, const char *const argv[])
{

  // create the options description object
  po::options_description options("Options");

  // initialize options
  init_options(options);

  // parse the command line and extract the variables map
  po::variables_map vm;
  parse_arguments(vm, options, argc, argv);

  // help message
  print_help(vm, options);

  if (vm.count("config-file"))
  {
    // set the parameters form the config file
    set_config_file(vm["config-file"].as<std::string>());
  }
  else
  {
    // set the parameters from the command line
    set_commmand_line(vm);
  }

  // print the configuration
  print_config(vm);

  // check parameters
  check_config();
}