#include "BitcoinExchange.hpp"

#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

namespace {

int numberAt(const std::string& text, std::size_t start, std::size_t length) {
  const std::string field = text.substr(start, length);
  std::istringstream input(field);
  int value;
  input >> value;
  return value;
}

void stripCarriageReturn(std::string& line) {
  if (line.empty()) return;

  const std::size_t last = line.size() - 1;
  if (line[last] == '\r') line.erase(last);
}

bool readLine(std::istream& stream, std::string& line) {
  std::getline(stream, line);
  if (stream.fail()) return false;

  stripCarriageReturn(line);
  return true;
}

bool isValidDate(const std::string& date) {
  if (date.size() != 10) return false;
  if (date[4] != '-' || date[7] != '-') return false;
  for (std::size_t i = 0; i < date.size(); ++i) {
    if (i == 4 || i == 7) continue;
    if (!std::isdigit(date[i])) return false;
  }

  const int year = numberAt(date, 0, 4);
  const int month = numberAt(date, 5, 2);
  const int day = numberAt(date, 8, 2);
  if (year == 0 || month < 1 || month > 12) return false;

  static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  const bool is_leap = year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
  const int limit = (month == 2 && is_leap) ? 29 : days[month - 1];
  return day >= 1 && day <= limit;
}

bool parseNumber(const std::string& text, double& value) {
  std::istringstream input(text);
  input >> value;
  if (input.fail() || value != value) return false;

  input >> std::ws;
  if (!input.eof()) return false;

  return true;
}

bool parseInputLine(const std::string& line, std::string& date, double& value) {
  const std::size_t separator = line.find(" | ");
  if (separator == std::string::npos) return false;

  date = line.substr(0, separator);
  const bool has_valid_date = isValidDate(date);
  if (!has_valid_date) return false;

  const std::string value_text = line.substr(separator + 3);
  return parseNumber(value_text, value);
}

}  // namespace

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& database_path) {
  std::ifstream database(database_path.c_str());
  if (!database.is_open()) throw std::runtime_error("could not open database.");

  std::string line;
  const bool has_header = readLine(database, line);
  if (!has_header) throw std::runtime_error("empty database.");
  if (line != "date,exchange_rate")
    throw std::runtime_error("invalid database header.");

  while (true) {
    const bool has_line = readLine(database, line);
    if (!has_line) break;

    const std::size_t separator = line.find(',');
    if (separator == std::string::npos)
      throw std::runtime_error("invalid database.");

    const std::string date = line.substr(0, separator);
    const bool has_valid_date = isValidDate(date);
    if (!has_valid_date) throw std::runtime_error("invalid database.");

    const std::string rate_text = line.substr(separator + 1);
    double rate;
    const bool has_valid_rate = parseNumber(rate_text, rate);
    if (!has_valid_rate || rate < 0)
      throw std::runtime_error("invalid database.");

    rates_[date] = rate;
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

void BitcoinExchange::process(const std::string& input_path) const {
  std::ifstream input(input_path.c_str());
  if (!input.is_open()) throw std::runtime_error("could not open file.");

  std::string line;
  const bool has_header = readLine(input, line);
  if (!has_header) throw std::runtime_error("empty input file.");
  if (line != "date | value") throw std::runtime_error("invalid input header.");

  while (true) {
    const bool has_line = readLine(input, line);
    if (!has_line) break;

    std::string date;
    double value;
    const bool parsed = parseInputLine(line, date, value);
    if (!parsed) {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue;
    }
    if (value < 0) {
      std::cerr << "Error: not a positive number." << std::endl;
      continue;
    }
    if (value > 1000) {
      std::cerr << "Error: too large a number." << std::endl;
      continue;
    }

    std::map<std::string, double>::const_iterator rate =
        rates_.upper_bound(date);
    if (rate == rates_.begin()) {
      std::cerr << "Error: date precedes database." << std::endl;
      continue;
    }

    --rate;
    std::cout << date << " => " << value << " = " << value * rate->second
              << std::endl;
  }
}
