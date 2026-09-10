#include <exception>
#include <iostream>
#include <stdexcept>

#include "RPN.hpp"

int main(int argc, char** argv) {
  try {
    if (argc != 2) throw std::runtime_error("empty expression.");

    const long result = RPN::evaluate(argv[1]);
    std::cout << result << std::endl;
  } catch (const std::exception& error) {
    std::cerr << "Error: " << error.what() << std::endl;
    return 1;
  }
  return 0;
}
