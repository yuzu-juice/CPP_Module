#include <exception>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  Intern someRandomIntern;
  AForm *shruberry, *robotomy, *presidential;

  shruberry = someRandomIntern.makeForm("shruberry creation", "target");
  robotomy = someRandomIntern.makeForm("rotobomy creation", "target");
  presidential = someRandomIntern.makeForm("presidential pardon", "target");

  // TODO: Print form detail

  delete shruberry;
  delete robotomy;
  delete presidential;
  return 0;
}
