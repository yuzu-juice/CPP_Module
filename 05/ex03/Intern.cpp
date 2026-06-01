#include "Intern.hpp"

Intern::Intern()
{
  std::cout << "[Constructor intern]" << std::endl;
}

Intern::Intern(const Intern &other)
{
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
