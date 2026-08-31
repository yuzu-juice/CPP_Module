#include <stdexcept>

template <typename InputIterator>
void Span::addNumber(InputIterator first, InputIterator last) {
  const std::vector<int> additions(first, last);
  if (additions.size() > capacity_ - numbers_.size()) {
    throw std::length_error("Span is full");
  }
  numbers_.insert(numbers_.end(), additions.begin(), additions.end());
}
