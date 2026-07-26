#include "ScalarConverter.hpp"

#include <cctype>
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>

namespace {

template <typename T>
void printChar(T value) {
  if (value != value || value < std::numeric_limits<char>::min() ||
      value > std::numeric_limits<char>::max()) {
    std::cout << "char: impossible\n";
    return;
  }
  const char converted = static_cast<char>(value);
  if (std::isprint(static_cast<unsigned char>(converted)))
    std::cout << "char: '" << converted << "'\n";
  else
    std::cout << "char: Non displayable\n";
}

template <typename T>
void printInt(T value) {
  if (value != value || value < std::numeric_limits<int>::min() ||
      value > std::numeric_limits<int>::max()) {
    std::cout << "int: impossible\n";
    return;
  }
  std::cout << "int: " << static_cast<int>(value) << "\n";
}

template <typename T>
void printFloating(const char* name, T value, const char* suffix) {
  std::cout << name << ": ";
  if (std::isnan(value))
    std::cout << "nan";
  else if (std::isinf(value))
    std::cout << (value < 0 ? "-inf" : "+inf");
  else {
    std::ostringstream output;
    output << value;
    const std::string result = output.str();
    std::cout << result;
    if (value == std::floor(value) &&
        result.find_first_of(".eE") == std::string::npos)
      std::cout << ".0";
  }
  std::cout << suffix << "\n";
}

}  // namespace

ScalarConverter::LiteralType ScalarConverter::detectType(
    const std::string& literal) {
  if (literal.length() == 1 &&
      !std::isdigit(static_cast<unsigned char>(literal[0])))
    return TYPE_CHAR;

  if (literal == "nanf" || literal == "+inff" || literal == "-inff")
    return TYPE_FLOAT;

  if (literal == "nan" || literal == "+inf" || literal == "-inf")
    return TYPE_DOUBLE;

  char* end = NULL;
  errno = 0;
  const long integer = std::strtol(literal.c_str(), &end, 10);
  if (end != literal.c_str() && *end == '\0') {
    if (errno == ERANGE || integer < std::numeric_limits<int>::min() ||
        integer > std::numeric_limits<int>::max())
      return TYPE_INVALID;
    return TYPE_INT;
  }

  end = NULL;
  errno = 0;
  const double decimal = std::strtod(literal.c_str(), &end);
  if (errno == ERANGE) return TYPE_INVALID;
  if (end != literal.c_str() && *end == 'f' && *(end + 1) == '\0') {
    if (decimal < -std::numeric_limits<float>::max() ||
        decimal > std::numeric_limits<float>::max())
      return TYPE_INVALID;
    return TYPE_FLOAT;
  }

  if (end != literal.c_str() && *end == '\0') return TYPE_DOUBLE;

  return TYPE_INVALID;
}

void ScalarConverter::convert(const std::string& literal) {
  switch (detectType(literal)) {
    case TYPE_CHAR:
      printValues(parseChar(literal));
      break;
    case TYPE_INT:
      printValues(parseInt(literal));
      break;
    case TYPE_FLOAT:
      printValues(parseFloat(literal));
      break;
    case TYPE_DOUBLE:
      printValues(parseDouble(literal));
      break;
    default:
      std::cout << "char: impossible\n"
                   "int: impossible\n"
                   "float: impossible\n"
                   "double: impossible\n";
  }
}

char ScalarConverter::parseChar(const std::string& literal) {
  return literal[0];
}

int ScalarConverter::parseInt(const std::string& literal) {
  return static_cast<int>(std::strtol(literal.c_str(), NULL, 10));
}

float ScalarConverter::parseFloat(const std::string& literal) {
  return static_cast<float>(std::strtod(literal.c_str(), NULL));
}

double ScalarConverter::parseDouble(const std::string& literal) {
  return std::strtod(literal.c_str(), NULL);
}

void ScalarConverter::printValues(int value) {
  printChar(value);
  std::cout << "int: " << value << "\n";
  printFloating("float", static_cast<float>(value), "f");
  printFloating("double", static_cast<double>(value), "");
}

void ScalarConverter::printValues(char value) {
  std::cout << "char: '" << value << "'\n";
  std::cout << "int: " << static_cast<int>(value) << "\n";
  printFloating("float", static_cast<float>(value), "f");
  printFloating("double", static_cast<double>(value), "");
}

void ScalarConverter::printValues(float value) {
  printChar(value);
  printInt(value);
  printFloating("float", value, "f");
  printFloating("double", static_cast<double>(value), "");
}

void ScalarConverter::printValues(double value) {
  printChar(value);
  printInt(value);
  if (!std::isinf(value) && !std::isnan(value) &&
      (value < -std::numeric_limits<float>::max() ||
       value > std::numeric_limits<float>::max()))
    std::cout << "float: impossible\n";
  else
    printFloating("float", static_cast<float>(value), "f");
  printFloating("double", value, "");
}
