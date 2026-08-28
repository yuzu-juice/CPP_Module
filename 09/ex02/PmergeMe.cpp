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

typedef std::pair<unsigned int, unsigned int> NumberPair;

void insertVectorValue(std::vector<unsigned int>& chain,
                       const NumberPair& pair) {
  std::vector<unsigned int>::iterator partner =
      std::find(chain.begin(), chain.end(), pair.first);
  chain.insert(std::lower_bound(chain.begin(), partner, pair.second),
               pair.second);
}

void insertVectorPending(std::vector<unsigned int>& chain,
                         const std::vector<NumberPair>& pairs) {
  std::size_t previous = 1;
  std::size_t jacobsthal = 3;
  while (previous < pairs.size()) {
    const std::size_t end = std::min(jacobsthal, pairs.size());
    for (std::size_t i = end; i > previous; --i)
      insertVectorValue(chain, pairs[i - 1]);
    const std::size_t next = jacobsthal + 2 * previous;
    previous = jacobsthal;
    jacobsthal = next;
  }
}

void insertDequeValue(std::deque<unsigned int>& chain, const NumberPair& pair) {
  std::deque<unsigned int>::iterator partner =
      std::find(chain.begin(), chain.end(), pair.first);
  chain.insert(std::lower_bound(chain.begin(), partner, pair.second),
               pair.second);
}

void insertDequePending(std::deque<unsigned int>& chain,
                        const std::deque<NumberPair>& pairs) {
  std::size_t previous = 1;
  std::size_t jacobsthal = 3;
  while (previous < pairs.size()) {
    const std::size_t end = std::min(jacobsthal, pairs.size());
    for (std::size_t i = end; i > previous; --i)
      insertDequeValue(chain, pairs[i - 1]);
    const std::size_t next = jacobsthal + 2 * previous;
    previous = jacobsthal;
    jacobsthal = next;
  }
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
  if (values.size() < 2) return;

  const bool has_odd = values.size() % 2 != 0;
  const unsigned int odd = has_odd ? values.back() : 0;
  std::vector<NumberPair> pairs;
  for (std::size_t i = 0; i + 1 < values.size(); i += 2) {
    if (values[i] < values[i + 1])
      pairs.push_back(NumberPair(values[i + 1], values[i]));
    else
      pairs.push_back(NumberPair(values[i], values[i + 1]));
  }

  std::vector<unsigned int> maxima;
  for (std::size_t i = 0; i < pairs.size(); ++i)
    maxima.push_back(pairs[i].first);
  sortVector(maxima);

  std::vector<NumberPair> ordered;
  for (std::size_t i = 0; i < maxima.size(); ++i) {
    std::vector<NumberPair>::iterator pair = pairs.begin();
    while (pair->first != maxima[i]) ++pair;
    ordered.push_back(*pair);
    pairs.erase(pair);
  }

  std::vector<unsigned int> chain;
  chain.push_back(ordered[0].second);
  chain.insert(chain.end(), maxima.begin(), maxima.end());
  insertVectorPending(chain, ordered);
  if (has_odd)
    chain.insert(std::lower_bound(chain.begin(), chain.end(), odd), odd);
  values.swap(chain);
}

void PmergeMe::sortDeque(std::deque<unsigned int>& values) {
  if (values.size() < 2) return;

  const bool has_odd = values.size() % 2 != 0;
  const unsigned int odd = has_odd ? values.back() : 0;
  std::deque<NumberPair> pairs;
  for (std::size_t i = 0; i + 1 < values.size(); i += 2) {
    if (values[i] < values[i + 1])
      pairs.push_back(NumberPair(values[i + 1], values[i]));
    else
      pairs.push_back(NumberPair(values[i], values[i + 1]));
  }

  std::deque<unsigned int> maxima;
  for (std::size_t i = 0; i < pairs.size(); ++i)
    maxima.push_back(pairs[i].first);
  sortDeque(maxima);

  std::deque<NumberPair> ordered;
  for (std::size_t i = 0; i < maxima.size(); ++i) {
    std::deque<NumberPair>::iterator pair = pairs.begin();
    while (pair->first != maxima[i]) ++pair;
    ordered.push_back(*pair);
    pairs.erase(pair);
  }

  std::deque<unsigned int> chain;
  chain.push_back(ordered[0].second);
  chain.insert(chain.end(), maxima.begin(), maxima.end());
  insertDequePending(chain, ordered);
  if (has_odd)
    chain.insert(std::lower_bound(chain.begin(), chain.end(), odd), odd);
  values.swap(chain);
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
