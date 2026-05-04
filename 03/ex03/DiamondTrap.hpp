#ifndef DIAMONDTRAP_HPP_
#define DIAMONDTRAP_HPP_

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
 public:
  DiamondTrap();
  DiamondTrap(const std::string &);

  ~DiamondTrap();

  DiamondTrap(const DiamondTrap &);

  DiamondTrap &operator=(const DiamondTrap &);

  std::string getName() const;
  using FragTrap::getAttackDamage;
  using FragTrap::getHitPoints;
  using ScavTrap::getEnergyPoints;

  void setName(std::string);
  using FragTrap::setAttackDamage;
  using FragTrap::setHitPoints;
  using ScavTrap::setEnergyPoints;

  using ScavTrap::attack;
  void takeDamage(unsigned int);
  void beRepaired(unsigned int);

  void whoAmI();

 private:
  std::string _name;
};

#endif
