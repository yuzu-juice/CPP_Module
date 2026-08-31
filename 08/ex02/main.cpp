#include <iostream>
#include <stack>

#include "MutantStack.hpp"

int main() {
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(7);
  mstack.push(0);

  MutantStack<int>::iterator it = mstack.begin();
  std::cout << *it << std::endl;
  *it = 6;
  std::cout << *mstack.begin() << std::endl;

  const MutantStack<int> copy(mstack);
  int index = 0;
  for (MutantStack<int>::const_iterator current = copy.begin();
       current != copy.end(); ++current) {
    std::cout << *current << std::endl;
    ++index;
  }
  std::cout << index << std::endl;

  std::stack<int> s(mstack);
  std::cout << s.top() << std::endl;
  std::cout << s.size() << std::endl;

  return 0;
}
