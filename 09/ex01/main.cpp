#include <exception>
#include <iostream>

#include "RPN.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Error" << std::endl;
    return 1;
  }
  try {
    std::cout << RPN::evaluate(argv[1]) << std::endl;
  } catch (const std::exception&) {
    std::cerr << "Error" << std::endl;
    return 1;
  }
  return 0;
}
