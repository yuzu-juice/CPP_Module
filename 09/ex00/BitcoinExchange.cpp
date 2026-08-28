#include "BitcoinExchange.hpp"

#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

namespace {

int numberAt(const std::string& text, std::size_t start, std::size_t length) {
  std::istringstream input(text.substr(start, length));
  int value;
  input >> value;
  return value;
}

void stripCarriageReturn(std::string& line) {
  if (!line.empty() && line[line.size() - 1] == '\r')
    line.erase(line.size() - 1);
}

}  // namespace

BitcoinExchange::BitcoinExchange(const std::string& database_path) {
  std::ifstream database(database_path.c_str());
  if (!database) throw std::runtime_error("could not open database.");

  std::string line;
  if (!std::getline(database, line))
    throw std::runtime_error("empty database.");
  stripCarriageReturn(line);
  if (line != "date,exchange_rate")
    throw std::runtime_error("invalid database header.");

  while (std::getline(database, line)) {
    stripCarriageReturn(line);
    const std::size_t separator = line.find(',');
    double rate;
    if (separator == std::string::npos ||
        !isValidDate(line.substr(0, separator)) ||
        !parseNumber(line.substr(separator + 1), rate) || rate < 0) {
      throw std::runtime_error("invalid database.");
    }
    rates_[line.substr(0, separator)] = rate;
  }
  if (rates_.empty()) throw std::runtime_error("empty database.");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : rates_(other.rates_) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
  if (this != &other) rates_ = other.rates_;
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(const std::string& date) {
  if (date.size() != 10 || date[4] != '-' || date[7] != '-') return false;
  for (std::size_t i = 0; i < date.size(); ++i) {
    if (i != 4 && i != 7 && !std::isdigit(static_cast<unsigned char>(date[i])))
      return false;
  }

  const int year = numberAt(date, 0, 4);
  const int month = numberAt(date, 5, 2);
  const int day = numberAt(date, 8, 2);
  if (year == 0 || month < 1 || month > 12) return false;

  static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int limit = days[month - 1];
  if (month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
    limit = 29;
  return day >= 1 && day <= limit;
}

bool BitcoinExchange::parseNumber(const std::string& text, double& value) {
  std::istringstream input(text);
  if (!(input >> value) || value != value) return false;
  input >> std::ws;
  return input.eof();
}

double BitcoinExchange::rateFor(const std::string& date) const {
  std::map<std::string, double>::const_iterator rate = rates_.lower_bound(date);
  if (rate != rates_.end() && rate->first == date) return rate->second;
  if (rate == rates_.begin())
    throw std::runtime_error("date precedes database");
  return (--rate)->second;
}

void BitcoinExchange::process(const std::string& input_path) const {
  std::ifstream input(input_path.c_str());
  if (!input) throw std::runtime_error("could not open file.");

  std::string line;
  if (!std::getline(input, line)) throw std::runtime_error("empty input file.");
  stripCarriageReturn(line);
  if (line != "date | value") throw std::runtime_error("invalid input header.");

  while (std::getline(input, line)) {
    stripCarriageReturn(line);
    const std::size_t separator = line.find(" | ");
    const std::string date = line.substr(0, separator);
    double value;
    if (separator == std::string::npos ||
        line.find(" | ", separator + 3) != std::string::npos ||
        !isValidDate(date) || !parseNumber(line.substr(separator + 3), value)) {
      std::cerr << "Error: bad input => " << line << std::endl;
    } else if (value < 0) {
      std::cerr << "Error: not a positive number." << std::endl;
    } else if (value > 1000) {
      std::cerr << "Error: too large a number." << std::endl;
    } else {
      try {
        const double result = value * rateFor(date);
        std::cout << date << " => " << value << " = " << result << std::endl;
      } catch (const std::exception&) {
        std::cerr << "Error: bad input => " << line << std::endl;
      }
    }
  }
}
