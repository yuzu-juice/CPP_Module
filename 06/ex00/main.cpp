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

  const char* cases[] = {"0",    "nan",  "42.0f", "42",    "-42",   "127",
                         "128",  "a",    "z",     "42.5f", "42.5",  "3.14f",
                         "3.14", "nanf", "+inf",  "-inf",  "+inff", "-inff",
                         "abc",  "42ff", "",      "."};
  for (unsigned int i = 0; i < sizeof(cases) / sizeof(cases[0]); ++i)
    test(cases[i]);
  return 0;
}
