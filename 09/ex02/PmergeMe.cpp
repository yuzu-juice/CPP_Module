#include "PmergeMe.hpp"

#include <algorithm>
#include <climits>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace {

unsigned int parse(const char* value) {
  const std::string text(value);
  const std::size_t not_a_digit = text.find_first_not_of("0123456789");
  if (not_a_digit != std::string::npos)
    throw std::runtime_error("invalid number.");

  std::istringstream input(text);
  unsigned long number;
  input >> number;
  if (input.fail()) throw std::runtime_error("invalid number.");
  if (number == 0 || number > UINT_MAX)
    throw std::runtime_error("invalid number.");

  return static_cast<unsigned int>(number);
}

double elapsedMicroseconds(std::clock_t start) {
  const std::clock_t ticks = std::clock() - start;
  return static_cast<double>(ticks) * 1000000.0 / CLOCKS_PER_SEC;
}

void printSequence(const char* label, const std::vector<unsigned int>& values) {
  std::cout << label;
  for (std::size_t i = 0; i < values.size(); ++i) std::cout << ' ' << values[i];
  std::cout << std::endl;
}

struct LessByValueInVector {
  explicit LessByValueInVector(const std::vector<unsigned int>& values)
      : values_(values) {}
  bool operator()(std::size_t x, std::size_t y) const {
    return values_[x] < values_[y];
  }
  const std::vector<unsigned int>& values_;
};

void mergeInsertionVector(std::vector<std::size_t>& items,
                          const std::vector<unsigned int>& values) {
  const std::size_t n = items.size();
  if (n < 2) return;

  std::vector<std::size_t> a;
  std::vector<std::size_t> partner(values.size());
  for (std::size_t i = 0; i + 1 < n; i += 2) {
    std::size_t big = items[i];
    std::size_t small = items[i + 1];
    if (values[big] < values[small]) std::swap(big, small);
    a.push_back(big);
    partner[big] = small;
  }

  mergeInsertionVector(a, values);

  std::vector<std::size_t> b;
  for (std::size_t i = 0; i < a.size(); ++i) b.push_back(partner[a[i]]);
  if (n % 2 != 0) b.push_back(items[n - 1]);

  std::vector<std::size_t> chain;
  chain.push_back(b[0]);
  chain.insert(chain.end(), a.begin(), a.end());

  const LessByValueInVector less(values);
  std::size_t previous = 1;
  std::size_t t = 3;
  while (previous < b.size()) {
    const std::size_t last = std::min(t, b.size());
    for (std::size_t j = last; j > previous; --j) {
      std::vector<std::size_t>::iterator bound = chain.end();
      if (j <= a.size())
        bound = std::find(chain.begin(), chain.end(), a[j - 1]);

      const std::size_t pending = b[j - 1];
      const std::vector<std::size_t>::iterator position =
          std::lower_bound(chain.begin(), bound, pending, less);
      chain.insert(position, pending);
    }
    const std::size_t next = t + 2 * previous;
    previous = t;
    t = next;
  }
  items.swap(chain);
}

void sortVector(std::vector<unsigned int>& values) {
  std::vector<std::size_t> order;
  for (std::size_t i = 0; i < values.size(); ++i) order.push_back(i);
  mergeInsertionVector(order, values);

  std::vector<unsigned int> sorted;
  for (std::size_t i = 0; i < order.size(); ++i)
    sorted.push_back(values[order[i]]);
  values.swap(sorted);
}

struct LessByValueInDeque {
  explicit LessByValueInDeque(const std::deque<unsigned int>& values)
      : values_(values) {}
  bool operator()(std::size_t x, std::size_t y) const {
    return values_[x] < values_[y];
  }
  const std::deque<unsigned int>& values_;
};

void mergeInsertionDeque(std::deque<std::size_t>& items,
                         const std::deque<unsigned int>& values) {
  const std::size_t n = items.size();
  if (n < 2) return;

  std::deque<std::size_t> a;
  std::deque<std::size_t> partner(values.size());
  for (std::size_t i = 0; i + 1 < n; i += 2) {
    std::size_t big = items[i];
    std::size_t small = items[i + 1];
    if (values[big] < values[small]) std::swap(big, small);
    a.push_back(big);
    partner[big] = small;
  }

  mergeInsertionDeque(a, values);

  std::deque<std::size_t> b;
  for (std::size_t i = 0; i < a.size(); ++i) b.push_back(partner[a[i]]);
  if (n % 2 != 0) b.push_back(items[n - 1]);

  std::deque<std::size_t> chain;
  chain.push_back(b[0]);
  chain.insert(chain.end(), a.begin(), a.end());

  const LessByValueInDeque less(values);
  std::size_t previous = 1;
  std::size_t t = 3;
  while (previous < b.size()) {
    const std::size_t last = std::min(t, b.size());
    for (std::size_t j = last; j > previous; --j) {
      std::deque<std::size_t>::iterator bound = chain.end();
      if (j <= a.size())
        bound = std::find(chain.begin(), chain.end(), a[j - 1]);

      const std::size_t pending = b[j - 1];
      const std::deque<std::size_t>::iterator position =
          std::lower_bound(chain.begin(), bound, pending, less);
      chain.insert(position, pending);
    }
    const std::size_t next = t + 2 * previous;
    previous = t;
    t = next;
  }
  items.swap(chain);
}

void sortDeque(std::deque<unsigned int>& values) {
  std::deque<std::size_t> order;
  for (std::size_t i = 0; i < values.size(); ++i) order.push_back(i);
  mergeInsertionDeque(order, values);

  std::deque<unsigned int> sorted;
  for (std::size_t i = 0; i < order.size(); ++i)
    sorted.push_back(values[order[i]]);
  values.swap(sorted);
}

}  // namespace

PmergeMe::PmergeMe() : vector_time_(0), deque_time_(0) {}

PmergeMe::PmergeMe(int count, char** values) : vector_time_(0), deque_time_(0) {
  std::clock_t start = std::clock();
  for (int i = 0; i < count; ++i) {
    const unsigned int number = parse(values[i]);
    vector_.push_back(number);
  }
  vector_time_ = elapsedMicroseconds(start);

  start = std::clock();
  for (int i = 0; i < count; ++i) {
    const unsigned int number = parse(values[i]);
    deque_.push_back(number);
  }
  deque_time_ = elapsedMicroseconds(start);
}

PmergeMe::PmergeMe(const PmergeMe& other)
    : vector_(other.vector_),
      deque_(other.deque_),
      vector_time_(other.vector_time_),
      deque_time_(other.deque_time_) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
  if (this != &other) {
    vector_ = other.vector_;
    deque_ = other.deque_;
    vector_time_ = other.vector_time_;
    deque_time_ = other.deque_time_;
  }
  return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::run() {
  printSequence("Before:", vector_);

  std::clock_t start = std::clock();
  sortVector(vector_);
  vector_time_ += elapsedMicroseconds(start);

  start = std::clock();
  sortDeque(deque_);
  deque_time_ += elapsedMicroseconds(start);

  const bool results_match =
      std::equal(vector_.begin(), vector_.end(), deque_.begin());
  if (!results_match) throw std::runtime_error("container results differ.");

  printSequence("After:", vector_);
  std::cout << std::fixed << std::setprecision(3)
            << "Time to process a range of " << vector_.size()
            << " elements with std::vector : " << vector_time_ << " us\n"
            << "Time to process a range of " << deque_.size()
            << " elements with std::deque : " << deque_time_ << " us"
            << std::endl;
}
