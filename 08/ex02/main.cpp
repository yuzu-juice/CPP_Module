#include <cassert>
#include <iostream>
#include <stack>

#include "MutantStack.hpp"

int main() {
  MutantStack<int> values;
  values.push(5);
  values.push(17);
  assert(values.top() == 17);
  values.pop();
  assert(values.size() == 1);
  values.push(3);
  values.push(7);
  values.push(0);

  MutantStack<int>::iterator it = values.begin();
  assert(*it == 5);
  *it = 6;
  assert(*values.begin() == 6);

  const MutantStack<int> copy(values);
  int expected[] = {6, 3, 7, 0};
  int index = 0;
  for (MutantStack<int>::const_iterator current = copy.begin();
       current != copy.end(); ++current) {
    assert(*current == expected[index++]);
  }
  assert(index == 4);

  std::stack<int> stack(values);
  assert(stack.top() == 0);
  assert(stack.size() == 4);

  std::cout << "All tests passed" << std::endl;
  return 0;
}
