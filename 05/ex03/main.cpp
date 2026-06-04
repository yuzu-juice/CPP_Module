#include <exception>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  Intern someRandomIntern;
  AForm *shruberry, *robotomy, *presidential, *other;

  shruberry = someRandomIntern.makeForm("shruberry creation", "target");
  robotomy = someRandomIntern.makeForm("robotomy request", "target");
  presidential = someRandomIntern.makeForm("presidential pardon", "target");
  other = someRandomIntern.makeForm("other form", "target");

  std::cout << *shruberry << std::endl;
  std::cout << *robotomy << std::endl;
  std::cout << *presidential << std::endl;
  std::cout << other << std::endl;

  delete shruberry;
  delete robotomy;
  delete presidential;
  return 0;
}
