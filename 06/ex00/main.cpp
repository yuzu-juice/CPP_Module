#include <iostream>

#include "ScalarConverter.hpp"

static void test(const std::string& literal) {
  std::cout << "input: " << literal << "\n";
  ScalarConverter::convert(literal);
  std::cout << "\n";
}

int main(int argc, char** argv) {
  if (argc == 2) {
    ScalarConverter::convert(argv[1]);
    return 0;
  }
  if (argc > 2) {
    std::cerr << "Usage: ./convert <literal>" << std::endl;
    return 1;
  }

  const char* cases[] = {
      // Subject examples
      "0", "nan", "42.0f",

      // Character and displayable ASCII boundaries
      "a", "Z", "*", ".", "-", "31", "32", "33", "126", "127", "128", "-128",
      "-129",

      // Integer boundaries
      "-2147483649", "-2147483648", "-2147483647", "2147483646", "2147483647",
      "2147483648",

      // Float/double to int boundaries
      "-2147483649.0f", "-2147483648.0f", "2147483520.0f", "2147483648.0f",
      "-2147483649.0", "-2147483648.0", "2147483647.0", "2147483648.0",

      // Float zero, subnormal, normal, maximum, and overflow
      "0.0f", "-0.0f", "1e-46f", "1.40129846e-45f", "1.17549435e-38f",
      "3.402823466e+38f", "3.4028236e+38f", "nanf", "+inff", "-inff",

      // Double zero, subnormal, normal, maximum, and overflow
      "0.0", "-0.0", "4.9406564584124654e-324", "2.2250738585072014e-308",
      "1.7976931348623157e+308", "1.7976931348623159e+308", "nan", "+inf",
      "-inf",

      // Double to float boundaries
      "3.402823466e+38", "3.4028236e+38",

      // Ordinary decimal forms and precision
      "-42", "+42", "42.5f", "42.5", "3.14f", "3.14", ".5f", "5.f", ".5", "5.",
      "42.00001f", "42.0000001",

      // Invalid forms
      "", " ", "abc", "42ff", "42.0ff", "--42", "++42", "1.2.3", "NaN", "nanff",
      "inf", "inff"};
  for (unsigned int i = 0; i < sizeof(cases) / sizeof(cases[0]); ++i)
    test(cases[i]);
  return 0;
}
