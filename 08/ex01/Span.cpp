#include "Span.hpp"

#include <algorithm>
#include <climits>
#include <stdexcept>

Span::Span(unsigned int capacity) : capacity_(capacity) {}

Span::Span(const Span& other)
    : numbers_(other.numbers_), capacity_(other.capacity_) {}

Span& Span::operator=(const Span& other) {
  if (this != &other) {
    numbers_ = other.numbers_;
    capacity_ = other.capacity_;
  }
  return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
  if (numbers_.size() == capacity_) throw std::length_error("Span is full");
  numbers_.push_back(number);
}

unsigned int Span::shortestSpan() const {
  if (numbers_.size() < 2) throw std::logic_error("No span available");

  std::vector<int> sorted(numbers_);
  std::sort(sorted.begin(), sorted.end());
  unsigned int shortest = UINT_MAX;
  for (std::size_t i = 1; i < sorted.size(); ++i) {
    const unsigned int distance = static_cast<unsigned int>(sorted[i]) -
                                  static_cast<unsigned int>(sorted[i - 1]);
    if (distance < shortest) shortest = distance;
  }
  return shortest;
}

unsigned int Span::longestSpan() const {
  if (numbers_.size() < 2) throw std::logic_error("No span available");

  return static_cast<unsigned int>(
             *std::max_element(numbers_.begin(), numbers_.end())) -
         static_cast<unsigned int>(
             *std::min_element(numbers_.begin(), numbers_.end()));
}
