#include "Form.hpp"

#include <iostream>
#include <ostream>

#include "Bureaucrat.hpp"

Form::Form()
    : _name("John Doe"),
      _is_signed(false),
      _required_grade_to_sign(150),
      _required_grade_to_execute(150) {
  std::cout << "[Constructor form]" << std::endl;
}

Form::Form(const std::string name, const int grade_to_sign,
           const int grade_to_execute)
    : _name(name),
      _is_signed(false),
      _required_grade_to_sign(grade_to_sign),
      _required_grade_to_execute(grade_to_execute) {
  std::cout << "[Constructor form with name and grades to operate]"
            << std::endl;
}

Form::Form(const Form &other)
    : _is_signed(other._is_signed),
      _required_grade_to_sign(other._required_grade_to_sign),
      _required_grade_to_execute(other._required_grade_to_execute) {
  std::cout << "[Copy constructor form]" << std::endl;
}

Form &Form::Form::operator=(const Form &other) {
  std::cout << "[Assignment operator overload form]" << std::endl;
  if (this != &other) {
    _is_signed = other._is_signed;
    // _required_grade_to_sign and _required_grade_to_execute must be constant,
    // so these can't be copy via copy assignment overload.
  }
  return *this;
}

Form::~Form() { std::cout << "[Destructor form]" << std::endl; }

const char *Form::GradeTooHighException::what() const throw() {
  return ("Grade too high.");
}

const char *Form::GradeTooLowException::what() const throw() {
  return ("Grade too low.");
}

std::string Form::getName() const { return _name; }

bool Form::getIsSigned() const { return _is_signed; }

int Form::getRequiredGradeToSign() const { return _required_grade_to_sign; }

int Form::getRequiredGradeToExecute() const {
  return _required_grade_to_execute;
}

void Form::beSigned(const Bureaucrat &b) {
  if (b.getGrade() > _required_grade_to_sign) throw GradeTooLowException();
  _is_signed = true;
}

std::ostream &operator<<(std::ostream &os, const Form &f) {
  os << "Name: " << f.getName()
     << "\nIs signed: " << (f.getIsSigned() ? "true" : "false")
     << "\nRequired grade to sign: " << f.getRequiredGradeToSign()
     << "\nRequired grade to execute: " << f.getRequiredGradeToExecute()
     << std::endl;
  return os;
}
