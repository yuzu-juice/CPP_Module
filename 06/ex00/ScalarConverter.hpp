#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
 public:
  ScalarConverter();
  ScalarConverter(const ScalarConverter& other);
  ScalarConverter& operator=(const ScalarConverter& other);
  ~ScalarConverter();

  static void convert(const std::string& literal);
};

#endif
