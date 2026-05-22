#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <iostream>

#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Jone Doe", 72, 45), _target("default") {
  std::cout << "[RobotomyRequestForm constructor]" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &name,
                                         const std::string &target)
    : AForm(name, 72, 45), _target(target) {
  std::cout << "[RobotomyRequestForm constructor with the name]" << std::endl;
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

void RobotomyRequestForm::execute(const Bureaucrat &executor) {
  if (executor.getGrade() > _required_grade_to_execute)
    throw GradeTooLowException();
  std::srand(time(NULL));
  if (std::rand() % 2 == 0)
    std::cout << _target << " has been robotomized." << std::endl;
  else
    std::cout << _target << " robotomy failed." << std::endl;
}
