#include <climits>
#include <iostream>
#include <vector>

#include "Span.hpp"

int main() {
  Span sample(5);
  sample.addNumber(6);
  sample.addNumber(3);
  sample.addNumber(17);
  sample.addNumber(9);
  sample.addNumber(11);
  std::cout << sample.shortestSpan() << std::endl;
  std::cout << sample.longestSpan() << std::endl;

  bool caught = false;
  try {
    sample.addNumber(42);
  } catch (const std::exception&) {
    caught = true;
  }
  std::cout << caught << std::endl;

  caught = false;
  try {
    Span empty(2);
    empty.shortestSpan();
  } catch (const std::exception&) {
    caught = true;
  }
  std::cout << caught << std::endl;

  Span extremes(2);
  extremes.addNumber(INT_MIN);
  extremes.addNumber(INT_MAX);
  std::cout << extremes.shortestSpan() << std::endl;
  std::cout << extremes.longestSpan() << std::endl;

  std::vector<int> input;
  for (int i = 0; i < 10000; ++i) input.push_back(i * 2);
  Span many(input.size());
  many.addNumber(input.begin(), input.end());
  std::cout << many.shortestSpan() << std::endl;
  std::cout << many.longestSpan() << std::endl;

  Span copy(many);
  std::cout << copy.shortestSpan() << std::endl;
  std::cout << copy.longestSpan() << std::endl;

  return 0;
}
