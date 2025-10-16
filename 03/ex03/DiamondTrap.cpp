#include "DiamondTrap.hpp"

#include <iostream>

// Constructor================================================
DiamondTrap::DiamondTrap() {
  std::cout << "DiamondTrap default constructor called." << std::endl;
  _hit_points = FragTrap::_hit_points;
  _energy_points = ScavTrap::_energy_points;
  _attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name") {
  std::cout << "DiamondTrap constructor called with string." << std::endl;
  _name = name;
  _hit_points = FragTrap::_hit_points;
  _energy_points = ScavTrap::_energy_points;
  _attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other) {
  std::cout << "DiamondTrap copy constructor called." << std::endl;
  _name = other._name;
  _hit_points = other.FragTrap::_hit_points;
  _energy_points = other.ScavTrap::_energy_points;
  _attack_damage = other.FragTrap::_attack_damage;
}
// ===========================================================

// Destructor=================================================
DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap destructor called." << std::endl;
}
// ===========================================================

// Copy assignment operator overload==========================
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
  std::cout << "DiamondTrap copy assignment operator called." << std::endl;
  if (this != &other) {
    _name = other._name;
    ClapTrap::_name = other.ClapTrap::_name;
    _hit_points = other.FragTrap::_hit_points;
    _energy_points = other.ScavTrap::_energy_points;
    _attack_damage = other.FragTrap::_attack_damage;
  }
  return *this;
}
// ===========================================================

// Method=====================================================
void DiamondTrap::takeDamage(unsigned int amount) {
  if (getHitPoints() == 0) {
    std::cout << "DiamondTrap " << _name << " has already died." << std::endl;
    return;
  }
  setHitPoints(std::max((int)(getHitPoints() - amount), 0));
  std::cout << "DiamondTrap " << _name << " took " << amount << " damages."
            << std::endl;
  if (getHitPoints() == 0)
    std::cout << "DiamondTrap " << _name << " is died." << std::endl;
}

void DiamondTrap::beRepaired(unsigned int amount) {
  if (getEnergyPoints() == 0) {
    std::cout << "DiamondTrap can't repair because of lack of energy points."
              << std::endl;
    return;
  }
  if (getHitPoints() == 0) {
    std::cout << "DiamondTrap can't repair because it has died." << std::endl;
    return;
  }
  setHitPoints(std::min(getHitPoints() + amount, Limits::MAX_HP));
  setEnergyPoints(getEnergyPoints() - 1);
  std::cout << "DiamondTrap " << _name << " repaired " << amount
            << " hit points." << std::endl;
}

void DiamondTrap::whoAmI() {
  if (getEnergyPoints() == 0) {
    std::cout << "DiamondTrap can't tell you who am I because of lack of "
                 "energy points."
              << std::endl;
    return;
  }
  if (getHitPoints() == 0) {
    std::cout << "DiamondTrap can't tell you who am I because it has died."
              << std::endl;
    return;
  }
  std::cout << "My name is " << _name << std::endl;
  std::cout << "My ClapTrap name is " << ClapTrap::getName() << std::endl;
}

// ===========================================================
