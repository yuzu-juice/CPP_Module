#ifndef SPAN_HPP_
#define SPAN_HPP_

#include <cstddef>
#include <iterator>
#include <stdexcept>
#include <vector>

class Span {
 public:
  explicit Span(unsigned int capacity);
  Span(const Span& other);
  Span& operator=(const Span& other);
  ~Span();

  void addNumber(int number);

  template <typename InputIterator>
  void addNumber(InputIterator first, InputIterator last) {
    const typename std::iterator_traits<InputIterator>::difference_type count =
        std::distance(first, last);
    if (count < 0 ||
        static_cast<std::size_t>(count) > capacity_ - numbers_.size()) {
      throw std::length_error("Span is full");
    }
    numbers_.insert(numbers_.end(), first, last);
  }

  unsigned int shortestSpan() const;
  unsigned int longestSpan() const;

 private:
  std::vector<int> numbers_;
  unsigned int capacity_;
};

#endif
