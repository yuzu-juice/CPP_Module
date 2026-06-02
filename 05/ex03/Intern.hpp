#ifndef INTERN_HPP_
#define INTERN_HPP_

#include <iostream>

#include "AForm.hpp"

class Intern {
 public:
  Intern();
  Intern(const Intern &);
  Intern &operator=(const Intern &);
  ~Intern();
  AForm *makeForm(const std::string &, const std::string &);
};

#endif
