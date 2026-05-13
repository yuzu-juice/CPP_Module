#include <exception>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
  Bureaucrat b = Bureaucrat("Alice");
  ShruberryCreationForm s = ShruberryCreationForm("ShruberryCreationForm", "Target");
	
  std::cout << b << std::endl;
  std::cout << s << std::endl;

  b.signForm(s); // Error

  std::cout << "-------------------------------" << std::endl;

  while (b.getGrade() > 145)
    b.incrementGrade();

	std::cout << b << std::endl;

	b.signForm(s); // Success
  
  std::cout << "-------------------------------" << std::endl;

	// TODO; add execute command test
  
  return 0;
}
