#include "RobotomyRequestForm.hpp"

#include <iostream>

#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Jone Doe", 72, 45), _target("default") {
  std::cout << "[RobotomyRequestForm constructor]" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), _target(other._target) {
  std::cout << "[RobotomyRequestForm copy constructor]" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    const RobotomyRequestForm &other) {
  std::cout << "[RobotomyRequestForm assignment operator overload]"
            << std::endl;
  if (this != &other) {
    // It can't copy anything because all attributes are constant.
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << "[RobotomyRequestForm destructor]" << std::endl;
}
