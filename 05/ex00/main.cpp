#include <exception>

#include "Bureaucrat.hpp"

int main() {
  Bureaucrat b = Bureaucrat();
  // instantiate
  std::cout << b << std::endl;

  // increment grade
  b.incrementGrade();
  std::cout << b << std::endl;

  // decrement grade
  b.decrementGrade();
  std::cout << b << std::endl;

  // throw grade too high
  try {
    while (true) {
      b.incrementGrade();
    }
  } catch (std::exception &e) {
    std::cout << b << std::endl;
    std::cerr << e.what() << std::endl;
  }

  // throw grade too low
  try {
    while (true) {
      b.decrementGrade();
    }
  } catch (std::exception &e) {
    std::cout << b << std::endl;
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
