#include <exception>
#include <iostream>
#include <stdexcept>

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
  try {
    if (argc < 2) throw std::runtime_error("empty sequence.");

    PmergeMe sorter(argc - 1, argv + 1);
    sorter.run();
  } catch (const std::exception& error) {
    std::cerr << "Error: " << error.what() << std::endl;
    return 1;
  }
  return 0;
}
