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
  std::cout << *found << std::endl;
  std::cout << (easyfind(numbers, 9) == numbers.end()) << std::endl;

  std::list<int> values;
  values.push_back(-3);
  values.push_back(7);
  std::list<int>::iterator list_found = easyfind(values, 7);
  std::cout << *list_found << std::endl;
  std::cout << (easyfind(values, 0) == values.end()) << std::endl;
  return 0;
}
