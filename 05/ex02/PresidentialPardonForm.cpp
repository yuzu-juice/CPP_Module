#include "PresidentialPardonForm.hpp"

#include <iostream>

#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("John Doe", 25, 5), _target("default") {
  std::cout << "[PresidentialPardonForm constructor]" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {
  std::cout << "[PresidentialPardonForm constructor with the target]"
            << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other), _target(other._target) {
  std::cout << "[PresidentialPardonForm copy constructor]" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(
    const PresidentialPardonForm &other) {
  std::cout << "[PresidentialPardonForm assignment operator overload]"
            << std::endl;
  if (this != &other) {
    // It can't copy anything because all attributes are constant.
  }
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << "[PresidentialPardonForm destructor]" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
  checkExecutable(executor);
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
