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
  std::cout << "vector find 4: " << (found == numbers.begin() ? "OK" : "NG")
            << std::endl;
  std::cout << "vector find 9: "
            << (easyfind(numbers, 9) == numbers.end() ? "OK" : "NG")
            << std::endl;

  std::list<int> values;
  values.push_back(-3);
  values.push_back(7);
  std::list<int>::iterator list_found = easyfind(values, 7);
  std::cout << "list find 7: "
            << (list_found != values.end() && *list_found == 7 ? "OK" : "NG")
            << std::endl;
  std::cout << "list find 0: "
            << (easyfind(values, 0) == values.end() ? "OK" : "NG") << std::endl;

  return 0;
}
