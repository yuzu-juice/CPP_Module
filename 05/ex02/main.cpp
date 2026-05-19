#include <exception>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  Bureaucrat b = Bureaucrat("Alice");
  ShruberryCreationForm s =
      ShruberryCreationForm("ShruberryCreationForm", "Hello");

  std::cout << b << std::endl;
  std::cout << s << std::endl;

  b.signForm(s);  // Error

  std::cout << "-------------------------------" << std::endl;

  while (b.getGrade() > 145) b.incrementGrade();

  std::cout << b << std::endl;

  b.signForm(s);  // Success

  std::cout << "-------------------------------" << std::endl;

  std::cout << b << std::endl;

  b.executeForm(s);  // Error

  std::cout << "-------------------------------" << std::endl;

  while (b.getGrade() > 137) b.incrementGrade();

  std::cout << b << std::endl;

  b.executeForm(s);  // Success

  std::cout << "-------------------------------" << std::endl;

  return 0;
}
