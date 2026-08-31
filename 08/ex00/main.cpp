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
  std::cout << "vector find 4: " << *found << std::endl;
  std::vector<int>::iterator vector_missing = easyfind(numbers, 9);
  std::cout << "vector find 9: ";
  if (vector_missing == numbers.end())
    std::cout << "not found";
  else
    std::cout << *vector_missing;
  std::cout << std::endl;

  std::list<int> values;
  values.push_back(-3);
  values.push_back(7);
  std::list<int>::iterator list_found = easyfind(values, 7);
  std::cout << "list find 7: " << *list_found << std::endl;
  std::list<int>::iterator list_missing = easyfind(values, 0);
  std::cout << "list find 0: ";
  if (list_missing == values.end())
    std::cout << "not found";
  else
    std::cout << *list_missing;
  std::cout << std::endl;
  return 0;
}
