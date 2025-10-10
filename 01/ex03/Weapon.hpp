#ifndef WEAPON_HPP_
#define WEAPON_HPP_

#include <string>

class Weapon {
 public:
  Weapon();
  Weapon(std::string);
  ~Weapon();
  std::string getType();
  void setType(std::string);

 private:
  std::string type;
};

#endif
