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
  std::cout << "sample shortest span: " << sample.shortestSpan()
            << " (expected 2)" << std::endl;
  std::cout << "sample longest span: " << sample.longestSpan()
            << " (expected 14)" << std::endl;

  bool caught = false;
  try {
    sample.addNumber(42);
  } catch (const std::exception&) {
    caught = true;
  }
  std::cout << "full span throws: " << (caught ? "yes" : "no") << std::endl;

  caught = false;
  try {
    Span empty(2);
    empty.shortestSpan();
  } catch (const std::exception&) {
    caught = true;
  }
  std::cout << "empty span throws: " << (caught ? "yes" : "no") << std::endl;

  Span extremes(2);
  extremes.addNumber(INT_MIN);
  extremes.addNumber(INT_MAX);
  std::cout << "extreme shortest span: " << extremes.shortestSpan()
            << " (expected " << UINT_MAX << ")" << std::endl;
  std::cout << "extreme longest span: " << extremes.longestSpan()
            << " (expected " << UINT_MAX << ")" << std::endl;

  std::vector<int> input;
  for (int i = 0; i < 10000; ++i) input.push_back(i * 2);
  Span many(input.size());
  many.addNumber(input.begin(), input.end());
  std::cout << "many shortest span: " << many.shortestSpan()
            << " (expected 2)" << std::endl;
  std::cout << "many longest span: " << many.longestSpan()
            << " (expected 19998)" << std::endl;

  Span copy(many);
  std::cout << "copy shortest span: " << copy.shortestSpan()
            << " (expected 2)" << std::endl;
  std::cout << "copy longest span: " << copy.longestSpan()
            << " (expected 19998)" << std::endl;

  return 0;
}
