#include <iostream>

#include "ScalarConverter.hpp"

static void test(const std::string& input) {
  std::cout << "input: " << input << std::endl;
  ScalarConverter::convert(input);
  std::cout << std::endl;
}

int main() {
  // Subject examples
  test("0");
  test("nan");
  test("42.0f");

  // Integer
  test("42");
  test("-42");
  test("127");
  test("128");

  // Character
  test("a");
  test("z");
  test("0");  // 数値の0

  // Float / Double
  test("42.5f");
  test("42.5");
  test("3.14f");
  test("3.14");

  // Pseudo literals
  test("nanf");
  test("+inf");
  test("-inf");
  test("+inff");
  test("-inff");

  // Invalid input
  test("abc");
  test("42ff");
  test("");
  test(".");

  return 0;
}
