#ifndef HARL_HPP_
#define HARL_HPP_

#include <string>

class Harl {
 public:
  Harl();
  ~Harl();
  void complain(std::string);

 private:
  void debug();
  void info();
  void warning();
  void error();
};

#endif
