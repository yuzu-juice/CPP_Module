#ifndef SPAN_HPP_
#define SPAN_HPP_

#include <vector>

class Span {
 public:
  explicit Span(unsigned int capacity);
  Span(const Span& other);
  Span& operator=(const Span& other);
  ~Span();

  void addNumber(int number);

  template <typename InputIterator>
  void addNumber(InputIterator first, InputIterator last);

  unsigned int shortestSpan() const;
  unsigned int longestSpan() const;

 private:
  std::vector<int> numbers_;
  unsigned int capacity_;
};

#include "Span.tpp"

#endif
