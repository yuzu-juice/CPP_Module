#ifndef DIAMONDTRAP_HPP_
#define DIAMONDTRAP_HPP_

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
 public:
  DiamondTrap();
  DiamondTrap(std::string);

  ~DiamondTrap();

  DiamondTrap(const DiamondTrap &);

  DiamondTrap &operator=(const DiamondTrap &);

  std::string getName() const;
  int getHitPoints() const;
  int getEnergyPoints() const;
  int getAttackDamage() const;

  void setName(std::string);
  void setHitPoints(int);
  void setEnergyPoints(int);
  void setAttackDamage(int);

  void attack(const std::string &);
  void takeDamage(unsigned int);
  void beRepaired(unsigned int);

  void whoAmI();

 private:
  std::string _name;
};

#endif
