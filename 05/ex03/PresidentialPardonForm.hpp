#ifndef PRESIDENTIAL_PARDON_FORM_
#define PRESIDENTIAL_PARDON_FORM_

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
 private:
  const std::string _target;

 public:
  PresidentialPardonForm();
  PresidentialPardonForm(const std::string &);
  PresidentialPardonForm(const std::string &, const std::string &);
  PresidentialPardonForm(const PresidentialPardonForm &);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &);
  ~PresidentialPardonForm();

  void execute(const Bureaucrat &);
};

#endif
