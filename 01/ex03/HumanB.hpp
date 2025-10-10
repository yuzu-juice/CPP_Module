#ifndef HUMANB_HPP_
#define HUMANB_HPP_

#include "Weapon.hpp"

class HumanB {
 public:
  HumanB(std::string name);
  ~HumanB();
  void attack();
  void setWeapon(Weapon& weapon);

 private:
  Weapon* weapon;
  std::string name;
};

#endif
