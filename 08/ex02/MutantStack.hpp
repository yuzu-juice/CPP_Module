#ifndef MUTANTSTACK_HPP_
#define MUTANTSTACK_HPP_

#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
 public:
  typedef typename Container::iterator iterator;
  typedef typename Container::const_iterator const_iterator;

  MutantStack();
  MutantStack(const MutantStack& other);
  MutantStack& operator=(const MutantStack& other);
  ~MutantStack();

  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;
};

#include "MutantStack.tpp"

#endif
