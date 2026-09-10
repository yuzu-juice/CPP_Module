#include <exception>
#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Usage: ./btc <input file>" << std::endl;
    return 1;
  }
  try {
    BitcoinExchange exchange("data.csv");
    exchange.process(argv[1]);
  } catch (const std::exception& error) {
    std::cerr << "Error: " << error.what() << std::endl;
    return 1;
  }
  return 0;
}
