#include "Bureaucrat.hpp"
#include <exception>

int main() {
  Bureaucrat b = Bureaucrat();
  // instantiate
  std::cout << b.getGrade() << std::endl;

  // increment grade
  b.incrementGrade();
  std::cout << b.getGrade() << std::endl;

  // decrement grade
  b.decrementGrade();
  std::cout << b.getGrade() << std::endl;

  // throw grade too high
  try {
    while (true) {
      b.incrementGrade();
    }
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  // throw grade too low
  try {
    while (true) {
      b.decrementGrade();
    }
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
