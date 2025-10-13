#include <iostream>

#include "Fixed.hpp"

int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));

  bool result1 = Fixed(10) > Fixed(1);
  std::cout << "10 > 1: " << result1 << std::endl;
  result1 = Fixed(10) < Fixed(1);
  std::cout << "10 < 1: " << result1 << std::endl;
  result1 = Fixed(10) >= Fixed(1);
  std::cout << "10 >= 1: " << result1 << std::endl;
  result1 = Fixed(10) <= Fixed(1);
  std::cout << "10 <= 1: " << result1 << std::endl;
  result1 = Fixed(1) >= Fixed(1);
  std::cout << "1 >= 1: " << result1 << std::endl;
  result1 = Fixed(1) <= Fixed(1);
  std::cout << "1 <= 1: " << result1 << std::endl;
  std::cout << std::endl;

  Fixed result2 = Fixed(10) + Fixed(1);
  std::cout << "10 + 1: " << result2 << std::endl;
  result2 = Fixed(10) - Fixed(1);
  std::cout << "10 - 1: " << result2 << std::endl;
  result2 = Fixed(10) * Fixed(1);
  std::cout << "10 * 1: " << result2 << std::endl;
  result2 = Fixed(10) / Fixed(1);
  std::cout << "10 / 1: " << result2 << std::endl;
  std::cout << std::endl;

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << --a << std::endl;
  std::cout << a << std::endl;
  std::cout << a-- << std::endl;
  std::cout << a << std::endl;
  std::cout << std::endl;

  std::cout << Fixed::min(a, b) << std::endl;
  std::cout << Fixed::max(a, b) << std::endl;

  return 0;
}
