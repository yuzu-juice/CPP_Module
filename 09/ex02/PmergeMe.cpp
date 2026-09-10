#include "PmergeMe.hpp"

#include <algorithm>
#include <climits>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

namespace {

template <typename Values>
struct LessByValue {
  explicit LessByValue(const Values& values) : values_(values) {}
  bool operator()(std::size_t x, std::size_t y) const {
    return values_[x] < values_[y];
  }
  const Values& values_;
};

template <typename Indices, typename Values>
void mergeInsertion(Indices& items, const Values& values) {
  const std::size_t n = items.size();
  if (n < 2) return;

  Indices a, partner(values.size());
  for (std::size_t i = 0; i + 1 < n; i += 2) {
    std::size_t big = items[i], small = items[i + 1];
    if (values[big] < values[small]) std::swap(big, small);
    a.push_back(big);
    partner[big] = small;
  }

  mergeInsertion(a, values);

  Indices b;
  for (std::size_t i = 0; i < a.size(); ++i) b.push_back(partner[a[i]]);
  if (n % 2 != 0) b.push_back(items[n - 1]);

  Indices chain;
  chain.push_back(b[0]);
  chain.insert(chain.end(), a.begin(), a.end());

  const LessByValue<Values> less(values);
  std::size_t previous = 1, t = 3;
  while (previous < b.size()) {
    const std::size_t last = std::min(t, b.size());
    for (std::size_t j = last; j > previous; --j) {
      const typename Indices::iterator bound =
          j <= a.size() ? std::find(chain.begin(), chain.end(), a[j - 1])
                        : chain.end();
      chain.insert(std::lower_bound(chain.begin(), bound, b[j - 1], less),
                   b[j - 1]);
    }
    const std::size_t next = t + 2 * previous;
    previous = t;
    t = next;
  }
  items.swap(chain);
}

template <typename Indices, typename Values>
void sortByMergeInsertion(Values& values) {
  Indices order;
  for (std::size_t i = 0; i < values.size(); ++i) order.push_back(i);
  mergeInsertion(order, values);
  Values sorted;
  for (std::size_t i = 0; i < order.size(); ++i)
    sorted.push_back(values[order[i]]);
  values.swap(sorted);
}

}  // namespace

PmergeMe::PmergeMe(int count, char** values) : vector_time_(0), deque_time_(0) {
  std::clock_t start = std::clock();
  for (int i = 0; i < count; ++i) vector_.push_back(parse(values[i]));
  vector_time_ =
      static_cast<double>(std::clock() - start) * 1000000.0 / CLOCKS_PER_SEC;

  start = std::clock();
  for (int i = 0; i < count; ++i) deque_.push_back(parse(values[i]));
  deque_time_ =
      static_cast<double>(std::clock() - start) * 1000000.0 / CLOCKS_PER_SEC;
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

unsigned int PmergeMe::parse(const char* value) {
  const std::string text(value);
  if (text.empty()) throw std::runtime_error("invalid number");
  for (std::size_t i = 0; i < text.size(); ++i)
    if (text[i] < '0' || text[i] > '9')
      throw std::runtime_error("invalid number");

  std::istringstream input(text);
  unsigned long number;
  input >> number;
  if (!input || !input.eof() || number == 0 || number > UINT_MAX)
    throw std::runtime_error("invalid number");
  return static_cast<unsigned int>(number);
}

void PmergeMe::sortVector(std::vector<unsigned int>& values) {
  sortByMergeInsertion<std::vector<std::size_t> >(values);
}

void PmergeMe::sortDeque(std::deque<unsigned int>& values) {
  sortByMergeInsertion<std::deque<std::size_t> >(values);
}

void PmergeMe::run() {
  std::cout << "Before:";
  for (std::size_t i = 0; i < vector_.size(); ++i)
    std::cout << ' ' << vector_[i];
  std::cout << std::endl;

  std::clock_t start = std::clock();
  sortVector(vector_);
  vector_time_ +=
      static_cast<double>(std::clock() - start) * 1000000.0 / CLOCKS_PER_SEC;
  start = std::clock();
  sortDeque(deque_);
  deque_time_ +=
      static_cast<double>(std::clock() - start) * 1000000.0 / CLOCKS_PER_SEC;
  if (!std::equal(vector_.begin(), vector_.end(), deque_.begin()))
    throw std::runtime_error("container results differ");

  std::cout << "After:";
  for (std::size_t i = 0; i < vector_.size(); ++i)
    std::cout << ' ' << vector_[i];
  std::cout << std::endl;
  std::cout << std::fixed << std::setprecision(3)
            << "Time to process a range of " << vector_.size()
            << " elements with std::vector : " << vector_time_ << " us\n"
            << "Time to process a range of " << deque_.size()
            << " elements with std::deque : " << deque_time_ << " us"
            << std::endl;
}
