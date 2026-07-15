#ifndef SHRUBBERY_CREATION_FORM_
#define SHRUBBERY_CREATION_FORM_

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {
 private:
  const std::string _target;

 public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string &);
  ShrubberyCreationForm(const std::string &, const std::string &);
  ShrubberyCreationForm(const ShrubberyCreationForm &);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);
  ~ShrubberyCreationForm();

  void execute(const Bureaucrat &) const;
};

#endif
