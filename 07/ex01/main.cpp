#include <cassert>
#include <iostream>
#include <string>

#include "iter.hpp"

template <typename T>
void increment(T& value) {
  ++value;
}

template <typename T>
void print(const T& value) {
  std::cout << value << std::endl;
}

int main() {
  int numbers[] = {1, 2, 3};

  ::iter(numbers, 3, increment<int>);
  assert(numbers[0] == 2);
  assert(numbers[1] == 3);
  assert(numbers[2] == 4);
  ::iter(numbers, 3, print<int>);

  const std::string words[] = {"one", "two"};

  ::iter(words, 2, print<std::string>);

  return 0;
}
