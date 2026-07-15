#include "AForm.hpp"

#include <iostream>
#include <ostream>

#include "Bureaucrat.hpp"

AForm::AForm()
    : _name("John Doe"),
      _is_signed(false),
      _required_grade_to_sign(150),
      _required_grade_to_execute(150) {
  std::cout << "[Constructor form]" << std::endl;
}

AForm::AForm(const std::string &name)
    : _name(name),
      _is_signed(false),
      _required_grade_to_sign(150),
      _required_grade_to_execute(150) {
  std::cout << "[Constructor form with the name]" << std::endl;
}

AForm::AForm(const std::string &name, const int grade_to_sign,
             const int grade_to_execute)
    : _name(name),
      _is_signed(false),
      _required_grade_to_sign(grade_to_sign),
      _required_grade_to_execute(grade_to_execute) {
  if (_required_grade_to_sign < 1 || _required_grade_to_execute < 1)
    throw GradeTooHighException();
  if (_required_grade_to_sign > 150 || _required_grade_to_execute > 150)
    throw GradeTooLowException();
  std::cout << "[Constructor form with name and grades to operate]"
            << std::endl;
}

AForm::AForm(const AForm &other)
    : _name(other._name),
      _is_signed(other._is_signed),
      _required_grade_to_sign(other._required_grade_to_sign),
      _required_grade_to_execute(other._required_grade_to_execute) {
  std::cout << "[Copy constructor form]" << std::endl;
}

AForm &AForm::operator=(const AForm &other) {
  std::cout << "[Assignment operator overload form]" << std::endl;
  if (this != &other) {
    _is_signed = other._is_signed;
    // _required_grade_to_sign and _required_grade_to_execute must be constant,
    // so these can't be copy via copy assignment overload.
  }
  return *this;
}

AForm::~AForm() { std::cout << "[Destructor form]" << std::endl; }

const char *AForm::GradeTooHighException::what() const throw() {
  return ("Grade too high.");
}

const char *AForm::GradeTooLowException::what() const throw() {
  return ("Grade too low.");
}

const char *AForm::FormNotSignedException::what() const throw() {
  return ("Form is not signed.");
}

std::string AForm::getName() const { return _name; }

bool AForm::getIsSigned() const { return _is_signed; }

int AForm::getRequiredGradeToSign() const { return _required_grade_to_sign; }

int AForm::getRequiredGradeToExecute() const {
  return _required_grade_to_execute;
}

void AForm::beSigned(const Bureaucrat &b) {
  if (b.getGrade() > _required_grade_to_sign) throw GradeTooLowException();
  _is_signed = true;
}

void AForm::checkExecutable(const Bureaucrat &executor) const {
  if (!_is_signed) throw FormNotSignedException();
  if (executor.getGrade() > _required_grade_to_execute)
    throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const AForm &f) {
  os << "Name: " << f.getName()
     << "\nIs signed: " << (f.getIsSigned() ? "true" : "false")
     << "\nRequired grade to sign: " << f.getRequiredGradeToSign()
     << "\nRequired grade to execute: " << f.getRequiredGradeToExecute()
     << std::endl;
  return os;
}
