#include <cassert>
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
  assert(sample.shortestSpan() == 2);
  assert(sample.longestSpan() == 14);

  bool caught = false;
  try {
    sample.addNumber(42);
  } catch (const std::exception&) {
    caught = true;
  }
  assert(caught);

  caught = false;
  try {
    Span empty(2);
    empty.shortestSpan();
  } catch (const std::exception&) {
    caught = true;
  }
  assert(caught);

  Span extremes(2);
  extremes.addNumber(INT_MIN);
  extremes.addNumber(INT_MAX);
  assert(extremes.shortestSpan() == UINT_MAX);
  assert(extremes.longestSpan() == UINT_MAX);

  std::vector<int> input;
  for (int i = 0; i < 10000; ++i) input.push_back(i * 2);
  Span many(input.size());
  many.addNumber(input.begin(), input.end());
  assert(many.shortestSpan() == 2);
  assert(many.longestSpan() == 19998);

  Span copy(many);
  assert(copy.shortestSpan() == 2);
  assert(copy.longestSpan() == 19998);

  std::cout << "All tests passed" << std::endl;
  return 0;
}
