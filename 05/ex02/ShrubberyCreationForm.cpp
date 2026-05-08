#include "ShrubberyCreationForm.hpp"

#include <iostream>

ShruberryCreationForm::ShruberryCreationForm() : AForm("John Doe", 145, 137), _target("default") {
  std::cout << "[ShruberryCreationForm constructor]" << std::endl;
}

ShruberryCreationForm::ShruberryCreationForm(const std::string &name, const std::string &target)
	: AForm(name, 145, 137), _target(target) {
  std::cout << "[ShruberryCreationForm constructor with the name]" << std::endl;
}

ShruberryCreationForm::ShruberryCreationForm(const ShruberryCreationForm &other)
	: AForm(other), _target(other._target) {
  std::cout << "[ShruberryCreationForm copy constructor]" << std::endl;
}

ShruberryCreationForm &ShruberryCreationForm::operator=(
    const ShruberryCreationForm &other) {
  std::cout << "[ShruberryCreationForm assignment operator overload]"
            << std::endl;
  if (this != &other) {
		// It can't copy anything because all attributes are constant.
  }
  return *this;
}

ShruberryCreationForm::~ShruberryCreationForm() {
	std::cout << "[ShruberryCreationForm destructor]" << std::endl;
}
