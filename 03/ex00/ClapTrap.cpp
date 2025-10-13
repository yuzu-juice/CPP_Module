#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap() { std::cout << "Constructor called." << std::endl; }

ClapTrap::ClapTrap(std::string name) : _name(name) {
  std::cout << "Constructor called with string." << std::endl;
}

ClapTrap::~ClapTrap() { std::cout << "Destructor called." << std::endl; }

void ClapTrap::attack(const std::string &target) {
  if (this->getEnergyPoints() <= 0) {
    std::cout << "ClapTrap can't attack because of lack of energy points."
              << std::endl;
    return;
  }
  this->setEnergyPoints(this->getEnergyPoints() - 1);
  std::cout << "ClapTrap " << this->_name << " attacks " << target
            << ", causing " << this->_attack_damage << " points of damage!"
            << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : {}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  if (this != &other) {
    this->setHitPoints(other.getHitPoints());
    this->setEnergyPoints(other.getEnergyPoints());
    this->setAttackDamage(other.getAttackDamage());
  }
  return *this;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (this->getHitPoints() <= 0) {
    std::cout << "ClapTrap " << this->_name << " has already died."
              << std::endl;
    return;
  }
  this->_hit_points--;
  std::cout << "ClapTrap " << this->_name << " took " << amount << " damages."
            << std::endl;
  if (this->_hit_points <= 0)
    std::cout << "ClapTrap " << this->_name << " is died." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (this->_energy_points <= 0) {
    std::cout << "ClapTrap can't repair because of lack of energy points."
              << std::endl;
    return;
  }
  this->_hit_points += amount;
  this->_energy_points--;
  std::cout << "ClapTrap " << this->_name << " repaired " << amount
            << " hit points." << std::endl;
}

void ClapTrap::setHitPoints(int hit_points) { this->_hit_points = hit_points; }

void ClapTrap::setEnergyPoints(int energy_points) {
  this->_energy_points = energy_points;
}

void ClapTrap::setAttackDamage(int attack_damage) {
  this->_attack_damage = attack_damage;
}

int ClapTrap::getHitPoints() const { return this->_hit_points; }

int ClapTrap::getEnergyPoints() const { return this->_energy_points; }

int ClapTrap::getAttackDamage() const { return this->_attack_damage; }
