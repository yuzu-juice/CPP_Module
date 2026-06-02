#include "Intern.hpp"

#include <iostream>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() { std::cout << "[Constructor intern]" << std::endl; }

Intern::Intern(const Intern &other) {
  (void)other;
  std::cout << "[Copy constructor Intern]" << std::endl;
}

Intern &Intern::Intern::operator=(const Intern &other) {
  std::cout << "[Assignment operator overload intern]" << std::endl;
  if (this != &other) {
    // _required_grade_to_sign and _required_grade_to_execute must be constant,
    // so these can't be copy via copy assignment overload.
  }
  return *this;
}

Intern::~Intern() { std::cout << "[Destructor intern]" << std::endl; }

AForm *Intern::makeForm(const std::string &form_name,
                        const std::string &target_name) {
  AForm *a;
  if (form_name == "PresidentialPardonForm")
    a = new PresidentialPardonForm(target_name);
  else if (form_name == "RobotomyRequestForm")
    a = new RobotomyRequestForm(target_name);
  else if (form_name == "ShruberryCreationForm")
    a = new ShruberryCreationForm(target_name);
  else {
    std::cout << "Intern creates nothing(NULL)" << std::endl;
    return NULL;
  }
  std::cout << "Intern creates " << form_name << std::endl;
  return a;
}
