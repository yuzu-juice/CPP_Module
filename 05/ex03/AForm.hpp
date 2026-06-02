#ifndef FORM_HPP_
#define FORM_HPP_

#include <exception>
#include <string>

class Bureaucrat;

class AForm {
 protected:
  const std::string _name;
  bool _is_signed;
  const int _required_grade_to_sign;
  const int _required_grade_to_execute;

 public:
  AForm();
  AForm(const std::string &name);
  AForm(const std::string &name, const int grade_to_sign,
        const int grade_to_execute);
  AForm(const AForm &);
  AForm &operator=(const AForm &);
  virtual ~AForm();

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
  void beSigned(const Bureaucrat &);
  virtual void execute(const Bureaucrat &) = 0;
};

std::ostream &operator<<(std::ostream &, const AForm &);

#endif
