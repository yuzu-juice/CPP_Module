#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap() {
  std::cout << "ScavTrap Constructor called." << std::endl;
  this->setHitPoints(100);
  this->setEnergyPoints(50);
  this->setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  std::cout << "ScavTrap Constructor called with string." << std::endl;
  this->setHitPoints(100);
  this->setEnergyPoints(50);
  this->setAttackDamage(20);
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap Destructor called." << std::endl;
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode."
            << std::endl;
}
