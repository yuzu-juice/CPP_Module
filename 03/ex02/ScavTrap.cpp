#include "ScavTrap.hpp"

#include <iostream>

// Constructor================================================
ScavTrap::ScavTrap() {
  std::cout << "ScavTrap default constructor called." << std::endl;
  this->setHitPoints(100);
  this->setEnergyPoints(50);
  this->setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  std::cout << "ScavTrap constructor called with string." << std::endl;
  this->setHitPoints(100);
  this->setEnergyPoints(50);
  this->setAttackDamage(20);
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
    this->setName(other.getName());
    this->setHitPoints(other.getHitPoints());
    this->setEnergyPoints(other.getEnergyPoints());
    this->setAttackDamage(other.getAttackDamage());
  }
  return *this;
}
// ===========================================================

// Method=====================================================
void ScavTrap::attack(const std::string &target) {
  if (this->getEnergyPoints() <= 0) {
    std::cout << "ScavTrap can't attack because of lack of energy points."
              << std::endl;
    return;
  }
  this->setEnergyPoints(this->getEnergyPoints() - 1);
  std::cout << "ScavTrap " << this->getName() << " attacks " << target
            << ", causing " << this->getAttackDamage() << " points of damage!"
            << std::endl;
}
void ScavTrap::takeDamage(unsigned int amount) {
  if (this->getHitPoints() <= 0) {
    std::cout << "ScavTrap " << this->getName() << " has already died."
              << std::endl;
    return;
  }
  this->setHitPoints(this->getHitPoints() - amount);
  std::cout << "ScavTrap " << this->getName() << " took " << amount
            << " damages." << std::endl;
  if (this->getHitPoints() <= 0)
    std::cout << "ScavTrap " << this->getName() << " is died." << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
  if (this->getEnergyPoints() <= 0) {
    std::cout << "ScavTrap can't repair because of lack of energy points."
              << std::endl;
    return;
  }
  this->setHitPoints(this->getHitPoints() + amount);
  this->setEnergyPoints(this->getEnergyPoints() - 1);
  std::cout << "ScavTrap " << this->getName() << " repaired " << amount
            << " hit points." << std::endl;
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode."
            << std::endl;
}
// ===========================================================
