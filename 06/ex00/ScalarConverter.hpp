#ifndef SCALARCONVERTER_HPP_
#define SCALARCONVERTER_HPP_

#include <string>

class ScalarConverter {
 public:
  static void convert(const std::string& literal);

 private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter& other);
  ScalarConverter& operator=(const ScalarConverter& other);
  ~ScalarConverter();
};

#endif
