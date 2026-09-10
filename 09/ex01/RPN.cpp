#include "RPN.hpp"

#include <climits>
#include <sstream>
#include <stack>
#include <stdexcept>

namespace {

bool isOperator(const std::string& token) {
  if (token.size() != 1) return false;

  const char symbol = token[0];
  return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

bool isSingleDigit(const std::string& token) {
  if (token.size() != 1) return false;
  return token[0] >= '0' && token[0] <= '9';
}

long calculate(long left, long right, char operation) {
  if (operation == '+') return left + right;
  if (operation == '-') return left - right;
  if (operation == '*') return left * right;
  if (right == 0 || (left == LONG_MIN && right == -1))
    throw std::runtime_error("invalid division.");
  return left / right;
}

}  // namespace

long RPN::evaluate(const std::string& expression) {
  std::istringstream input(expression);
  std::stack<long> values;
  std::string token;

  while (true) {
    input >> token;
    if (input.fail()) break;

    const bool is_value = isSingleDigit(token);
    if (is_value) {
      values.push(token[0] - '0');
      continue;
    }

    const bool is_applicable = isOperator(token) && values.size() >= 2;
    if (!is_applicable) throw std::runtime_error("invalid expression.");

    const long right = values.top();
    values.pop();
    const long left = values.top();
    values.pop();

    const long result = calculate(left, right, token[0]);
    values.push(result);
  }
  if (values.size() != 1) throw std::runtime_error("invalid expression.");
  return values.top();
}

RPN::RPN() {}
RPN::RPN(const RPN&) {}
RPN& RPN::operator=(const RPN&) { return *this; }
RPN::~RPN() {}
