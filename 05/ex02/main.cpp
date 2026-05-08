#include <exception>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

int main() {
  Bureaucrat b = Bureaucrat("Alice");
  AForm f = AForm("AForm1", 150, 150);

  std::cout << b << std::endl;
  std::cout << f << std::endl;

  b.signForm(f);  // Success

  std::cout << "-------------------------------" << std::endl;

  AForm g = AForm("AForm2", 100, 100);

  std::cout << b << std::endl;
  std::cout << g << std::endl;

  b.signForm(g);  // Error

  return 0;
}
