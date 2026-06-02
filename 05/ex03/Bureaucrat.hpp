#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

#include <exception>
#include <iostream>
#include <string>

class AForm;

class Bureaucrat {
 private:
  const std::string _name;
  int _grade;

 public:
  Bureaucrat();
  Bureaucrat(const std::string &);
  Bureaucrat(const Bureaucrat &);
  Bureaucrat &operator=(const Bureaucrat &);
  ~Bureaucrat();

  std::string getName() const;
  int getGrade() const;
  void incrementGrade();
  void decrementGrade();

  class GradeTooHighException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

  void signForm(AForm &) const;
  void executeForm(AForm &) const;
};

std::ostream &operator<<(std::ostream &, const Bureaucrat &);

#endif
