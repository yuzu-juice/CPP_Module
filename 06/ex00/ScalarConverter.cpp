#include "ScalarConverter.hpp"

#include <cctype>
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

namespace {

enum LiteralType { TYPE_CHAR, TYPE_INT, TYPE_FLOAT, TYPE_DOUBLE, TYPE_INVALID };

bool isCharRange(long double value) {
  return value >= static_cast<long double>(std::numeric_limits<char>::min()) &&
         value <= static_cast<long double>(std::numeric_limits<char>::max());
}

bool isIntRange(long double value) {
  return value >= static_cast<long double>(std::numeric_limits<int>::min()) &&
         value <= static_cast<long double>(std::numeric_limits<int>::max());
}

bool isNan(double value) { return value != value; }

bool isInfinity(double value) {
  return value > std::numeric_limits<double>::max() ||
         value < -std::numeric_limits<double>::max();
}

void printCharValue(char value) {
  if (std::isprint(static_cast<unsigned char>(value)))
    std::cout << "char: '" << value << "'\n";
  else
    std::cout << "char: Non displayable\n";
}

void printChar(long double value) {
  if (!isCharRange(value)) {
    std::cout << "char: impossible\n";
    return;
  }
  printCharValue(static_cast<char>(value));
}

void printInt(long double value) {
  if (!isIntRange(value)) {
    std::cout << "int: impossible\n";
    return;
  }
  std::cout << "int: " << static_cast<int>(value) << "\n";
}

void printFloatingValue(double value, int precision) {
  if (isNan(value))
    std::cout << "nan";
  else if (isInfinity(value))
    std::cout << (value < 0 ? "-inf" : "+inf");
  else {
    std::ostringstream output;
    output << std::setprecision(precision) << value;
    const std::string result = output.str();
    std::cout << result;
    if (value == std::floor(value) &&
        result.find_first_of(".eE") == std::string::npos)
      std::cout << ".0";
  }
}

void printFloat(float value, int precision) {
  std::cout << "float: ";
  printFloatingValue(static_cast<double>(value), precision);
  std::cout << "f\n";
}

void printDouble(double value, int precision) {
  std::cout << "double: ";
  printFloatingValue(value, precision);
  std::cout << "\n";
}

LiteralType detectType(const std::string& literal) {
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
  if (errno == ERANGE && (decimal == HUGE_VAL || decimal == -HUGE_VAL))
    return TYPE_INVALID;
  if (isNan(decimal) || isInfinity(decimal)) return TYPE_INVALID;
  if (end != literal.c_str() && *end == 'f' && *(end + 1) == '\0' &&
      literal.find_first_of(".eE") != std::string::npos) {
    if (decimal < -std::numeric_limits<float>::max() ||
        decimal > std::numeric_limits<float>::max())
      return TYPE_INVALID;
    return TYPE_FLOAT;
  }

  if (end != literal.c_str() && *end == '\0') return TYPE_DOUBLE;

  return TYPE_INVALID;
}

void printValues(int value) {
  printChar(value);
  std::cout << "int: " << value << "\n";
  printFloat(static_cast<float>(value), std::numeric_limits<float>::digits10);
  printDouble(static_cast<double>(value),
              std::numeric_limits<double>::digits10);
}

void printValues(char value) {
  printCharValue(value);
  std::cout << "int: " << static_cast<int>(value) << "\n";
  printFloat(static_cast<float>(value), std::numeric_limits<float>::digits10);
  printDouble(static_cast<double>(value),
              std::numeric_limits<double>::digits10);
}

void printValues(float value) {
  printChar(value);
  printInt(value);
  printFloat(value, std::numeric_limits<float>::digits10);
  printDouble(static_cast<double>(value), std::numeric_limits<float>::digits10);
}

void printValues(double value) {
  printChar(value);
  printInt(value);
  if (!isInfinity(value) && !isNan(value) &&
      (value < -std::numeric_limits<float>::max() ||
       value > std::numeric_limits<float>::max()))
    std::cout << "float: impossible\n";
  else
    printFloat(static_cast<float>(value), std::numeric_limits<float>::digits10);
  printDouble(value, std::numeric_limits<double>::digits10);
}

}  // namespace

void ScalarConverter::convert(const std::string& literal) {
  switch (detectType(literal)) {
    case TYPE_CHAR:
      printValues(literal[0]);
      break;
    case TYPE_INT:
      printValues(static_cast<int>(std::strtol(literal.c_str(), NULL, 10)));
      break;
    case TYPE_FLOAT:
      printValues(static_cast<float>(std::strtod(literal.c_str(), NULL)));
      break;
    case TYPE_DOUBLE:
      printValues(std::strtod(literal.c_str(), NULL));
      break;
    default:
      std::cout << "char: impossible\n"
                   "int: impossible\n"
                   "float: impossible\n"
                   "double: impossible\n";
  }
}
