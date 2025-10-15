#include "ScavTrap.hpp"

#include <iostream>

// Constructor================================================
ScavTrap::ScavTrap() {
  std::cout << "ScavTrap default constructor called." << std::endl;
  setHitPoints(100);
  setEnergyPoints(50);
  setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  std::cout << "ScavTrap constructor called with string." << std::endl;
  setHitPoints(100);
  setEnergyPoints(50);
  setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
  std::cout << "ScavTrap copy constructor called." << std::endl;
}
// ===========================================================

// Destructor=================================================
ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap destructor called." << std::endl;
}
// ===========================================================

// Copy assignment operator overload==========================
ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  std::cout << "ScavTrap copy assignment operator called." << std::endl;
  if (this != &other) {
    setName(other.getName());
    setHitPoints(other.getHitPoints());
    setEnergyPoints(other.getEnergyPoints());
    setAttackDamage(other.getAttackDamage());
  }
  return *this;
}
// ===========================================================

// Method=====================================================
void ScavTrap::attack(const std::string &target) {
  if (getEnergyPoints() <= 0) {
    std::cout << "ScavTrap can't attack because of lack of energy points."
              << std::endl;
    return;
  }
  setEnergyPoints(getEnergyPoints() - 1);
  std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing "
            << getAttackDamage() << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
  if (getHitPoints() <= 0) {
    std::cout << "ScavTrap " << getName() << " has already died." << std::endl;
    return;
  }
  setHitPoints(getHitPoints() - amount);
  std::cout << "ScavTrap " << getName() << " took " << amount << " damages."
            << std::endl;
  if (getHitPoints() <= 0)
    std::cout << "ScavTrap " << getName() << " is died." << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
  if (getEnergyPoints() <= 0) {
    std::cout << "ScavTrap can't repair because of lack of energy points."
              << std::endl;
    return;
  }
  setHitPoints(getHitPoints() + amount);
  setEnergyPoints(getEnergyPoints() - 1);
  std::cout << "ScavTrap " << getName() << " repaired " << amount
            << " hit points." << std::endl;
}

void ScavTrap::guardGate() {
  if (getEnergyPoints() <= 0) {
    std::cout << "ScavTrap can't switch to Gate keeper mode because of lack of "
                 "energy points."
              << std::endl;
    return;
  }
  std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode."
            << std::endl;
}
// ===========================================================
