#ifndef BITCOINEXCHANGE_HPP_
#define BITCOINEXCHANGE_HPP_

#include <map>
#include <string>

class BitcoinExchange {
 public:
  explicit BitcoinExchange(const std::string& database_path);
  BitcoinExchange(const BitcoinExchange& other);
  BitcoinExchange& operator=(const BitcoinExchange& other);
  ~BitcoinExchange();

  void process(const std::string& input_path) const;

 private:
  std::map<std::string, double> rates_;

  static bool isValidDate(const std::string& date);
  static bool parseNumber(const std::string& text, double& value);
  double rateFor(const std::string& date) const;
};

#endif
