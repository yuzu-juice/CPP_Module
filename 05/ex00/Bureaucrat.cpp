#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("John Doe"), _grade(150) {
  std::cout << "[Constructor]" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string s) : _name(s), _grade(150) {
  std::cout << "[Constructor with the name]" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : _name(other._name), _grade(other._grade) {
  std::cout << "[Copy constructor]" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  std::cout << "[Assignment operator overload]" << std::endl;
  if (this != &other) {
    _grade = other._grade;
  }
  return *this;
}

Bureaucrat::~Bureaucrat() {
  std::cout << "[Destructor]" << std::endl;
}

std::string Bureaucrat::getName() const {
  return _name;
}

int Bureaucrat::getGrade() const {
  return _grade;
}

void Bureaucrat::incrementGrade() {
  if (_grade <= 1) {
    throw;
  }
  ++_grade;
}

void Bureaucrat::decrementGrade() {
  if (_grade >= 150) {
    throw;
  }
  --_grade;
}
