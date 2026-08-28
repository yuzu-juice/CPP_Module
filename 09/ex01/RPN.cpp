#include "RPN.hpp"

#include <climits>
#include <sstream>
#include <stack>
#include <stdexcept>

namespace {

bool isOperator(const std::string& token) {
  return token.size() == 1 && (token[0] == '+' || token[0] == '-' ||
                               token[0] == '*' || token[0] == '/');
}

long calculate(long left, long right, char operation) {
  if (operation == '+') {
    if ((right > 0 && left > LONG_MAX - right) ||
        (right < 0 && left < LONG_MIN - right))
      throw std::runtime_error("overflow");
    return left + right;
  }
  if (operation == '-') {
    if ((right < 0 && left > LONG_MAX + right) ||
        (right > 0 && left < LONG_MIN + right))
      throw std::runtime_error("overflow");
    return left - right;
  }
  if (operation == '/') {
    if (right == 0 || (left == LONG_MIN && right == -1))
      throw std::runtime_error("invalid division");
    return left / right;
  }
  if (left == 0 || right == 0) return 0;
  if ((left > 0 && right > 0 && left > LONG_MAX / right) ||
      (left > 0 && right < 0 && right < LONG_MIN / left) ||
      (left < 0 && right > 0 && left < LONG_MIN / right) ||
      (left < 0 && right < 0 && left < LONG_MAX / right))
    throw std::runtime_error("overflow");
  return left * right;
}

}  // namespace

long RPN::evaluate(const std::string& expression) {
  std::istringstream input(expression);
  std::stack<long> values;
  std::string token;

  while (input >> token) {
    if (token.size() == 1 && token[0] >= '0' && token[0] <= '9') {
      values.push(token[0] - '0');
    } else if (isOperator(token) && values.size() >= 2) {
      const long right = values.top();
      values.pop();
      const long left = values.top();
      values.pop();
      values.push(calculate(left, right, token[0]));
    } else {
      throw std::runtime_error("invalid expression");
    }
  }
  if (values.size() != 1) throw std::runtime_error("invalid expression");
  return values.top();
}

RPN::RPN() {}
RPN::RPN(const RPN&) {}
RPN& RPN::operator=(const RPN&) { return *this; }
RPN::~RPN() {}
