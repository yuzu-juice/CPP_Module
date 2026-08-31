#include <iostream>
#include <stack>

#include "MutantStack.hpp"

int main() {
  MutantStack<int> values;
  values.push(5);
  values.push(17);
  std::cout << values.top() << std::endl;
  values.pop();
  std::cout << values.size() << std::endl;
  values.push(3);
  values.push(7);
  values.push(0);

  MutantStack<int>::iterator it = values.begin();
  std::cout << *it << std::endl;
  *it = 6;
  std::cout << *values.begin() << std::endl;

  const MutantStack<int> copy(values);
  int index = 0;
  for (MutantStack<int>::const_iterator current = copy.begin();
       current != copy.end(); ++current) {
    std::cout << *current << std::endl;
    ++index;
  }
  std::cout << index << std::endl;

  std::stack<int> stack(values);
  std::cout << stack.top() << std::endl;
  std::cout << stack.size() << std::endl;

  return 0;
}
