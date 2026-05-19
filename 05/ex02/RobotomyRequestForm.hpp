#ifndef ROBOTOMY_REQUEST_FORM_
#define ROBOTOMY_REQUEST_FORM_

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
 private:
  const std::string _target;

 public:
  RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm &);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &);
  ~RobotomyRequestForm();

  void execute(const Bureaucrat &);
};

#endif
