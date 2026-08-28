#include <cassert>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

int main() {
  std::vector<int> numbers;
  numbers.push_back(4);
  numbers.push_back(2);
  numbers.push_back(4);

  std::vector<int>::iterator found = easyfind(numbers, 4);
  assert(found == numbers.begin());
  assert(easyfind(numbers, 9) == numbers.end());

  std::list<int> values;
  values.push_back(-3);
  values.push_back(7);
  assert(*easyfind(values, 7) == 7);
  assert(easyfind(values, 0) == values.end());

  std::cout << "All tests passed" << std::endl;
  return 0;
}
