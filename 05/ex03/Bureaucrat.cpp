#include "Bureaucrat.hpp"

#include <ostream>

#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("John Doe"), _grade(150) {
  std::cout << "[Constructor bureaucrat]" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &s) : _name(s), _grade(150) {
  std::cout << "[Constructor bureaucrat with the name]" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : _name(other._name), _grade(other._grade) {
  std::cout << "[Copy constructor bureaucrat]" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  std::cout << "[Assignment operator overload bureaucrat]" << std::endl;
  if (this != &other) {
    _grade = other._grade;
  }
  return *this;
}

Bureaucrat::~Bureaucrat() {
  std::cout << "[Destructor bureaucrat]" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {
  os << b.getName() << ", breaucrat grade " << b.getGrade();
  return os;
}

std::string Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade() {
  if (_grade <= 1) {
    throw GradeTooHighException();
  }
  --_grade;
}

void Bureaucrat::decrementGrade() {
  if (_grade >= 150) {
    throw GradeTooLowException();
  }
  ++_grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Grade too high.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Grade too low.");
}

void Bureaucrat::signForm(AForm &f) const {
  try {
    f.beSigned(*this);
    std::cout << getName() << " signed " << f.getName() << "." << std::endl;
  } catch (std::exception &e) {
    std::cerr << getName() << " couldn't sign " << f.getName() << " because "
              << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(AForm &form) const {
  try {
    form.execute(*this);
    std::cout << getName() << " executed " << form.getName() << "."
              << std::endl;
  } catch (std::exception &e) {
    std::cerr << getName() << " couldn't execute " << form.getName()
              << " because " << e.what() << std::endl;
  }
}
