#ifndef INTERN_HPP_
#define INTERN_HPP_

#include <iostream>

class Intern {
public:
  Intern();
  Intern(const Intern &);
	Intern &operator=(const Intern&);
	~Intern();
  void makeForm(std::string &, std::string &);
};

#endif
