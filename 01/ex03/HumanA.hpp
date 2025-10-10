#ifndef HUMANA_HPP_
#define HUMANA_HPP_

#include "Weapon.hpp"

class HumanA {
 public:
  HumanA(std::string name, Weapon& weapon);
  ~HumanA();
  void attack();

 private:
  std::string name;
  Weapon& weapon;
};

#endif
