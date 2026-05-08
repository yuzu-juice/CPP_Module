#ifndef SHRUBERRY_CREATION_FORM_
#define SHRUBERRY_CREATION_FORM_

#include "AForm.hpp"

class ShruberryCreationForm : public AForm {
 private:
  const std::string _target;

 public:
  ShruberryCreationForm();
  ShruberryCreationForm(const std::string &, const std::string &);
  ShruberryCreationForm(const ShruberryCreationForm &);
  ShruberryCreationForm &operator=(const ShruberryCreationForm &);
  ~ShruberryCreationForm();
};

#endif
