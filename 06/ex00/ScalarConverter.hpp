#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
 public:
  static void convert(const std::string& literal);

 private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter& other);
  ScalarConverter& operator=(const ScalarConverter& other);
  ~ScalarConverter();

  enum LiteralType {
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_INVALID
  };

  static LiteralType detectType(const std::string& literal);

  static char parseChar(const std::string& literal);
  static int parseInt(const std::string& literal);
  static float parseFloat(const std::string& literal);
  static double parseDouble(const std::string& literal);
  static void printValues(char value);
  static void printValues(int value);
  static void printValues(float value);
  static void printValues(double value);
  static void printImpossible();
};

#endif
