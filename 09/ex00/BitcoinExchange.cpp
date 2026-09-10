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
  const bool ends_with_carriage_return = line[last] == '\r';
  if (!ends_with_carriage_return) return;

  line.erase(last);
}

bool readLine(std::istream& stream, std::string& line) {
  std::getline(stream, line);
  if (stream.fail()) return false;

  stripCarriageReturn(line);
  return true;
}

bool hasDateLayout(const std::string& date) {
  if (date.size() != 10) return false;
  if (date[4] != '-') return false;
  if (date[7] != '-') return false;

  for (std::size_t i = 0; i < date.size(); ++i) {
    if (i == 4 || i == 7) continue;

    const unsigned char character = date[i];
    const bool is_digit = std::isdigit(character) != 0;
    if (!is_digit) return false;
  }
  return true;
}

int daysInMonth(int year, int month) {
  static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month != 2) return days[month - 1];

  const bool is_leap = year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
  if (is_leap) return 29;
  return 28;
}

bool isValidDate(const std::string& date) {
  const bool has_layout = hasDateLayout(date);
  if (!has_layout) return false;

  const int year = numberAt(date, 0, 4);
  const int month = numberAt(date, 5, 2);
  const int day = numberAt(date, 8, 2);
  if (year == 0) return false;
  if (month < 1 || month > 12) return false;
  if (day < 1) return false;

  const int limit = daysInMonth(year, month);
  return day <= limit;
}

bool parseNumber(const std::string& text, double& value) {
  std::istringstream input(text);
  input >> value;
  if (input.fail()) return false;

  const bool is_not_a_number = value != value;
  if (is_not_a_number) return false;

  input >> std::ws;
  return input.eof();
}

bool parseInputLine(const std::string& line, std::string& date, double& value) {
  const std::size_t separator = line.find(" | ");
  if (separator == std::string::npos) return false;

  const std::size_t extra_separator = line.find(" | ", separator + 3);
  if (extra_separator != std::string::npos) return false;

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
  const bool opened = database.is_open();
  if (!opened) throw std::runtime_error("could not open database.");

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
    if (!has_valid_rate) throw std::runtime_error("invalid database.");
    if (rate < 0) throw std::runtime_error("invalid database.");

    rates_[date] = rate;
  }

  const bool is_empty = rates_.empty();
  if (is_empty) throw std::runtime_error("empty database.");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : rates_(other.rates_) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
  if (this != &other) rates_ = other.rates_;
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

double BitcoinExchange::rateFor(const std::string& date) const {
  std::map<std::string, double>::const_iterator rate = rates_.lower_bound(date);

  const bool is_exact_match = rate != rates_.end() && rate->first == date;
  if (is_exact_match) return rate->second;

  const bool has_earlier_rate = rate != rates_.begin();
  if (!has_earlier_rate) throw std::runtime_error("date precedes database.");

  --rate;
  return rate->second;
}

void BitcoinExchange::process(const std::string& input_path) const {
  std::ifstream input(input_path.c_str());
  const bool opened = input.is_open();
  if (!opened) throw std::runtime_error("could not open file.");

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

    try {
      const double rate = rateFor(date);
      const double result = value * rate;
      std::cout << date << " => " << value << " = " << result << std::endl;
    } catch (const std::exception&) {
      std::cerr << "Error: bad input => " << line << std::endl;
    }
  }
}
