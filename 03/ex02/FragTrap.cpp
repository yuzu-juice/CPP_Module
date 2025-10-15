#include "FragTrap.hpp"

#include <iostream>

#include "ClapTrap.hpp"

// Constructor================================================
FragTrap::FragTrap() {
  std::cout << "FragTrap default constructor called." << std::endl;
  this->setHitPoints(100);
  this->setEnergyPoints(100);
  this->setAttackDamage(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  std::cout << "FragTrap constructor called with string." << std::endl;
  this->setHitPoints(100);
  this->setEnergyPoints(100);
  this->setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
  std::cout << "FragTrap copy constructor called." << std::endl;
}
// ===========================================================

// Destructor=================================================
FragTrap::~FragTrap() {
  std::cout << "FragTrap destructor called." << std::endl;
}
// ===========================================================

// Copy assignment operator overload==========================
FragTrap &FragTrap::operator=(const FragTrap &other) {
  std::cout << "FragTrap copy assignment operator called." << std::endl;
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
void FragTrap::attack(const std::string &target) {
  if (this->getEnergyPoints() <= 0) {
    std::cout << "FragTrap can't attack because of lack of energy points."
              << std::endl;
    return;
  }
  this->setEnergyPoints(this->getEnergyPoints() - 1);
  std::cout << "FragTrap " << this->getName() << " attacks " << target
            << ", causing " << this->getAttackDamage() << " points of damage!"
            << std::endl;
}
void FragTrap::takeDamage(unsigned int amount) {
  if (this->getHitPoints() <= 0) {
    std::cout << "FragTrap " << this->getName() << " has already died."
              << std::endl;
    return;
  }
  this->setHitPoints(this->getHitPoints() - amount);
  std::cout << "FragTrap " << this->getName() << " took " << amount
            << " damages." << std::endl;
  if (this->getHitPoints() <= 0)
    std::cout << "FragTrap " << this->getName() << " is died." << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
  if (this->getEnergyPoints() <= 0) {
    std::cout << "FragTrap can't repair because of lack of energy points."
              << std::endl;
    return;
  }
  this->setHitPoints(this->getHitPoints() + amount);
  this->setEnergyPoints(this->getEnergyPoints() - 1);
  std::cout << "FragTrap " << this->getName() << " repaired " << amount
            << " hit points." << std::endl;
}

void FragTrap::highFivesGuys() {
  std::cout << "Give me high five!" << std::endl;
}
// ===========================================================
