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

  RobotomyRequestForm r = RobotomyRequestForm("RobotomyRequestForm", "Hello");

  std::cout << b << std::endl;

  b.signForm(r);  // Error

  std::cout << "-------------------------------" << std::endl;

  while (b.getGrade() > 72) b.incrementGrade();

  std::cout << b << std::endl;

  b.signForm(r);  // Success

  std::cout << "-------------------------------" << std::endl;

  std::cout << b << std::endl;

  b.executeForm(r);  // Error

  std::cout << "-------------------------------" << std::endl;

  while (b.getGrade() > 45) b.incrementGrade();

  std::cout << b << std::endl;

  b.executeForm(r);  // Success

  std::cout << "-------------------------------" << std::endl;
  return 0;
}
