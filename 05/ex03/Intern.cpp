#include "Intern.hpp"

#include <iostream>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

namespace {

AForm *createPresidentialPardonForm(const std::string &target) {
  return new PresidentialPardonForm(target);
}

AForm *createRobotomyRequestForm(const std::string &target) {
  return new RobotomyRequestForm(target);
}

AForm *createShrubberyCreationForm(const std::string &target) {
  return new ShrubberyCreationForm(target);
}

}  // namespace

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
  const std::string form_names[3] = {"presidential pardon", "robotomy request",
                                     "shrubbery creation"};
  AForm *(*const form_creators[3])(const std::string &) = {
      &createPresidentialPardonForm, &createRobotomyRequestForm,
      &createShrubberyCreationForm};

  for (int i = 0; i < 3; ++i) {
    if (form_name == form_names[i]) {
      std::cout << "Intern creates " << form_name << std::endl;
      return form_creators[i](target_name);
    }
  }
  std::cout << "Intern creates nothing" << std::endl;
  return NULL;
}
