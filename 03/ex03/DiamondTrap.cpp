#include "DiamondTrap.hpp"

#include <iostream>

// Constructor================================================
DiamondTrap::DiamondTrap() {
  std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") {
  std::cout << "DiamondTrap constructor called with string." << std::endl;
  this->setName(name);
  this->setHitPoints(100);
  this->setEnergyPoints(100);
  this->setAttackDamage(30);
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other) {
  std::cout << "DiamondTrap copy constructor called." << std::endl;
  this->setName(other.getName());
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
    this->setName(other.DiamondTrap::getName());
    this->ClapTrap::setName(other.DiamondTrap::getName() + "_clap_name");
    this->setHitPoints(other.getHitPoints());
    this->setEnergyPoints(other.getEnergyPoints());
    this->setAttackDamage(other.getAttackDamage());
  }
  return *this;
}
// ===========================================================

// Setter=====================================================
void DiamondTrap::setName(std::string name) { this->_name = name; }

void DiamondTrap::setHitPoints(int hit_points) {
  this->FragTrap::setHitPoints(hit_points);
}

void DiamondTrap::setEnergyPoints(int energy_points) {
  this->ScavTrap::setEnergyPoints(energy_points);
}

void DiamondTrap::setAttackDamage(int attack_damage) {
  this->FragTrap::setAttackDamage(attack_damage);
}
// ===========================================================

// Getter=====================================================
std::string DiamondTrap::getName() const { return this->_name; }

int DiamondTrap::getHitPoints() const { return this->FragTrap::getHitPoints(); }

int DiamondTrap::getEnergyPoints() const {
  return this->ScavTrap::getEnergyPoints();
}

int DiamondTrap::getAttackDamage() const {
  return this->FragTrap::getAttackDamage();
}
// ===========================================================

// Method=====================================================
void DiamondTrap::attack(const std::string &target) {
  this->ScavTrap::attack(target);
}
void DiamondTrap::takeDamage(unsigned int amount) {
  if (this->getHitPoints() <= 0) {
    std::cout << "DiamondTrap " << this->getName() << " has already died."
              << std::endl;
    return;
  }
  this->setHitPoints(this->getHitPoints() - amount);
  std::cout << "DiamondTrap " << this->getName() << " took " << amount
            << " damages." << std::endl;
  if (this->getHitPoints() <= 0)
    std::cout << "DiamondTrap " << this->getName() << " is died." << std::endl;
}
void DiamondTrap::beRepaired(unsigned int amount) {
  if (this->getEnergyPoints() <= 0) {
    std::cout << "DiamondTrap can't repair because of lack of energy points."
              << std::endl;
    return;
  }
  this->setHitPoints(this->getHitPoints() + amount);
  this->setEnergyPoints(this->getEnergyPoints() - 1);
  std::cout << "DiamondTrap " << this->getName() << " repaired " << amount
            << " hit points." << std::endl;
}

void DiamondTrap::whoAmI() {
  if (this->getEnergyPoints() <= 0) {
    std::cout << "DiamondTrap can't tell you who am I because of lack of "
                 "energy points."
              << std::endl;
    return;
  }
  std::cout << "My name is " << this->DiamondTrap::getName() << std::endl;
  std::cout << "My ClapTrap name is " << this->ClapTrap::getName() << std::endl;
}

// ===========================================================
