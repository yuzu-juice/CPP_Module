#include <exception>
#include <iostream>
#include <string>

#include "Array.hpp"

int main() {
  Array<int> empty;
  std::cout << "empty size: " << empty.size() << std::endl;

  Array<int> numbers(3);
  std::cout << "numbers size: " << numbers.size() << std::endl;
  std::cout << "initial values: " << numbers[0] << ", " << numbers[1] << ", "
            << numbers[2] << std::endl;

  numbers[0] = 10;
  numbers[1] = 20;
  numbers[2] = 30;

  Array<int> copied(numbers);
  copied[0] = 99;

  std::cout << "numbers[0]: " << numbers[0] << std::endl;
  std::cout << "copied[0]: " << copied[0] << std::endl;

  Array<int> assigned;
  assigned = numbers;
  assigned[0] = 88;

  std::cout << "numbers[0]: " << numbers[0] << std::endl;
  std::cout << "assigned[0]: " << assigned[0] << std::endl;

  Array<int>* same_array = &assigned;
  assigned = *same_array;

  std::cout << "after self assignment: " << assigned[0] << ", " << assigned[1]
            << ", " << assigned[2] << std::endl;

  const Array<int> const_numbers(numbers);
  std::cout << "const_numbers[0]: " << const_numbers[0] << std::endl;

  try {
    numbers[99] = 42;
  } catch (const std::exception& e) {
    std::cout << "exception caught: " << e.what() << std::endl;
  }

  Array<std::string> words(2);
  std::cout << "initial words: " << words[0] << ", " << words[1] << std::endl;

  words[0] = "hello";
  words[1] = "templates";

  std::cout << "words: " << words[0] << ", " << words[1] << std::endl;

  return 0;
}
