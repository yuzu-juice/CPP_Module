#include <cassert>
#include <exception>
#include <iostream>
#include <string>

#include "Array.hpp"

int main() {
  Array<int> empty;
  assert(empty.size() == 0);

  Array<int> numbers(3);
  assert(numbers.size() == 3);
  assert(numbers[0] == 0);
  assert(numbers[1] == 0);
  assert(numbers[2] == 0);

  numbers[0] = 10;
  numbers[1] = 20;
  numbers[2] = 30;

  Array<int> copied(numbers);
  copied[0] = 99;
  assert(numbers[0] == 10);
  assert(copied[0] == 99);

  Array<int> assigned;
  assigned = numbers;
  assigned[1] = 88;
  assert(numbers[1] == 20);
  assert(assigned[1] == 88);

  Array<int>* same_array = &assigned;
  assigned = *same_array;
  assert(assigned[0] == 10);
  assert(assigned[1] == 88);
  assert(assigned[2] == 30);

  const Array<int> const_numbers(numbers);
  assert(const_numbers[2] == 30);

  bool caught = false;
  try {
    numbers[3] = 42;
  } catch (const std::exception&) {
    caught = true;
  }
  assert(caught);

  Array<std::string> words(2);
  assert(words[0].empty());
  assert(words[1].empty());
  words[0] = "hello";
  words[1] = "templates";
  assert(words[0] == "hello");
  assert(words[1] == "templates");

  std::cout << "All tests passed" << std::endl;
  return 0;
}
