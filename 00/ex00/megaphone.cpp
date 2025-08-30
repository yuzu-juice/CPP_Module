#include "main.hpp"

std::string megaphone(std::string s) {
  std::string transformed_s;

  for (std::string::iterator it = s.begin(); it != s.end(); it++) {
    transformed_s += std::toupper(*it);
  }
  return (transformed_s);
}
