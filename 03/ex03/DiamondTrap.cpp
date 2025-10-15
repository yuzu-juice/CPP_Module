#include "DiamondTrap.hpp"

#include <iostream>

// Constructor================================================
DiamondTrap::DiamondTrap() {
  std::cout << "DiamondTrap default constructor called." << std::endl;
  setHitPoints(getHitPoints());
  setEnergyPoints(getEnergyPoints());
  setAttackDamage(getAttackDamage());
}

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name") {
  std::cout << "DiamondTrap constructor called with string." << std::endl;
  _name = name;
  setHitPoints(getHitPoints());
  setEnergyPoints(getEnergyPoints());
  setAttackDamage(getAttackDamage());
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other) {
  std::cout << "DiamondTrap copy constructor called." << std::endl;
  _name = other._name;
  setHitPoints(other.getHitPoints());
  setEnergyPoints(other.getEnergyPoints());
  setAttackDamage(other.getAttackDamage());
}
// ===========================================================

// Destructor=================================================
DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap destructor called." << std::endl;
}
// ===========================================================

// Copy assignment operator overload==========================
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
  std::cout << "DiamondTrap copy assignment operator called." << std::endl;
  if (this != &other) {
    _name = other._name;
    ClapTrap::setName(other.ClapTrap::getName());
    setHitPoints(other.getHitPoints());
    setEnergyPoints(other.getEnergyPoints());
    setAttackDamage(other.getAttackDamage());
  }
  return *this;
}
// ===========================================================

// Method=====================================================
void DiamondTrap::takeDamage(unsigned int amount) {
  if (getHitPoints() <= 0) {
    std::cout << "DiamondTrap " << _name << " has already died." << std::endl;
    return;
  }
  setHitPoints(getHitPoints() - amount);
  std::cout << "DiamondTrap " << _name << " took " << amount << " damages."
            << std::endl;
  if (getHitPoints() <= 0)
    std::cout << "DiamondTrap " << _name << " is died." << std::endl;
}

void DiamondTrap::beRepaired(unsigned int amount) {
  if (getEnergyPoints() <= 0) {
    std::cout << "DiamondTrap can't repair because of lack of energy points."
              << std::endl;
    return;
  }
  setHitPoints(getHitPoints() + amount);
  setEnergyPoints(getEnergyPoints() - 1);
  std::cout << "DiamondTrap " << _name << " repaired " << amount
            << " hit points." << std::endl;
}

void DiamondTrap::whoAmI() {
  if (getEnergyPoints() <= 0) {
    std::cout << "DiamondTrap can't tell you who am I because of lack of "
                 "energy points."
              << std::endl;
    return;
  }
  std::cout << "My name is " << _name << std::endl;
  std::cout << "My ClapTrap name is " << ClapTrap::getName() << std::endl;
}

// ===========================================================
