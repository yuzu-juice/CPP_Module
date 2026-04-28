#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

#include <iostream>
#include <string>

class Bureaucrat {
 private:
  const std::string _name;
  int _grade;

 public:
  Bureaucrat();
  Bureaucrat(const std::string);
  Bureaucrat(const Bureaucrat &);
  Bureaucrat &operator=(const Bureaucrat &);
  ~Bureaucrat();

  std::string getName() const;
  int getGrade() const;
  void incrementGrade();
  void decrementGrade();
};

#endif
