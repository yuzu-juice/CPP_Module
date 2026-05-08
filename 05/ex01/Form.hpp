#ifndef FORM_HPP_
#define FORM_HPP_

#include <exception>
#include <string>

class Bureaucrat;

class Form {
 private:
  const std::string _name;
  bool _is_signed;
  const int _required_grade_to_sign;
  const int _required_grade_to_execute;

 public:
  Form();
  Form(const std::string name, const int grade_to_sign,
       const int grade_to_execute);
  Form(const Form &);
  Form &operator=(const Form &);
  ~Form();

  class GradeTooHighException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

  std::string getName() const;
  bool getIsSigned() const;
  int getRequiredGradeToSign() const;
  int getRequiredGradeToExecute() const;
  void beSigned(Bureaucrat &);
};

std::ostream &operator<<(std::ostream &, const Form &);

#endif
