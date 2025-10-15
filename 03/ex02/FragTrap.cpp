#include "FragTrap.hpp"

#include <iostream>

#include "ClapTrap.hpp"

// Constructor================================================
FragTrap::FragTrap() {
  std::cout << "FragTrap default constructor called." << std::endl;
  setHitPoints(100);
  setEnergyPoints(100);
  setAttackDamage(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  std::cout << "FragTrap constructor called with string." << std::endl;
  setHitPoints(100);
  setEnergyPoints(100);
  setAttackDamage(30);
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
    setName(other.getName());
    setHitPoints(other.getHitPoints());
    setEnergyPoints(other.getEnergyPoints());
    setAttackDamage(other.getAttackDamage());
  }
  return *this;
}
// ===========================================================

// Method=====================================================
void FragTrap::attack(const std::string &target) {
  if (getEnergyPoints() <= 0) {
    std::cout << "FragTrap can't attack because of lack of energy points."
              << std::endl;
    return;
  }
  setEnergyPoints(getEnergyPoints() - 1);
  std::cout << "FragTrap " << getName() << " attacks " << target
            << ", causing " << getAttackDamage() << " points of damage!"
            << std::endl;
}
void FragTrap::takeDamage(unsigned int amount) {
  if (getHitPoints() <= 0) {
    std::cout << "FragTrap " << getName() << " has already died."
              << std::endl;
    return;
  }
  setHitPoints(getHitPoints() - amount);
  std::cout << "FragTrap " << getName() << " took " << amount
            << " damages." << std::endl;
  if (getHitPoints() <= 0)
    std::cout << "FragTrap " << getName() << " is died." << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
  if (getEnergyPoints() <= 0) {
    std::cout << "FragTrap can't repair because of lack of energy points."
              << std::endl;
    return;
  }
  setHitPoints(getHitPoints() + amount);
  setEnergyPoints(getEnergyPoints() - 1);
  std::cout << "FragTrap " << getName() << " repaired " << amount
            << " hit points." << std::endl;
}

void FragTrap::highFivesGuys() {
  if (getEnergyPoints() <= 0) {
    std::cout << "FragTrap can't do high five because of lack of energy points."
              << std::endl;
    return;
  }
  std::cout << "Give me high five!" << std::endl;
}
// ===========================================================
