#ifndef PMERGEME_HPP_
#define PMERGEME_HPP_

#include <deque>
#include <vector>

class PmergeMe {
 public:
  PmergeMe(int count, char** values);
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);
  ~PmergeMe();

  void run();

 private:
  std::vector<unsigned int> vector_;
  std::deque<unsigned int> deque_;
  double vector_time_;
  double deque_time_;

  static unsigned int parse(const char* value);
  static void sortVector(std::vector<unsigned int>& values);
  static void sortDeque(std::deque<unsigned int>& values);
};

#endif
