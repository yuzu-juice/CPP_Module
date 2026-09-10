#include <exception>
#include <iostream>

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "Usage: ./PmergeMe <positive integer> [...]" << std::endl;
    return 1;
  }
  try {
    PmergeMe sorter(argc - 1, argv + 1);
    sorter.run();
  } catch (const std::exception& error) {
    std::cerr << "Error: " << error.what() << std::endl;
    return 1;
  }
  return 0;
}
