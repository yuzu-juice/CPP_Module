#include <exception>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  Intern someRandomIntern;
  AForm *shrubbery, *robotomy, *presidential, *other;

  shrubbery = someRandomIntern.makeForm("shrubbery creation", "target");
  robotomy = someRandomIntern.makeForm("robotomy request", "target");
  presidential = someRandomIntern.makeForm("presidential pardon", "target");
  other = someRandomIntern.makeForm("other form", "target");

  std::cout << *shrubbery << std::endl;
  std::cout << *robotomy << std::endl;
  std::cout << *presidential << std::endl;
  std::cout << other << std::endl;

  delete shrubbery;
  delete robotomy;
  delete presidential;
  return 0;
}
