#include <exception>
#include <iostream>
#include <stdexcept>

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
  try {
    if (argc != 2) throw std::runtime_error("could not open file.");

    BitcoinExchange exchange("data.csv");
    exchange.process(argv[1]);
  } catch (const std::exception& error) {
    std::cerr << "Error: " << error.what() << std::endl;
    return 1;
  }
  return 0;
}
