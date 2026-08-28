#ifndef RPN_HPP_
#define RPN_HPP_

#include <string>

class RPN {
 public:
  static long evaluate(const std::string& expression);

 private:
  RPN();
  RPN(const RPN& other);
  RPN& operator=(const RPN& other);
  ~RPN();
};

#endif
