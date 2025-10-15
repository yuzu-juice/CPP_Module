#include "ScavTrap.hpp"

#include <algorithm>
#include <iostream>

// Constructor================================================
ScavTrap::ScavTrap() {
  std::cout << "ScavTrap default constructor called." << std::endl;
  _hit_points = 100;
  _energy_points = 50;
  _attack_damage = 20;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
  std::cout << "ScavTrap constructor called with string." << std::endl;
  _hit_points = 100;
  _energy_points = 50;
  _attack_damage = 20;
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
    _name = other._name;
    _hit_points = other._hit_points;
    _energy_points = other._energy_points;
    _attack_damage = other._attack_damage;
  }
  return *this;
}
// ===========================================================

// Method=====================================================
void ScavTrap::attack(const std::string &target) {
  if (_energy_points == 0) {
    std::cout << "ScavTrap can't attack because of lack of energy points."
              << std::endl;
    return;
  }
  if (_hit_points == 0) {
    std::cout << "ScavTrap can't attack because it has died." << std::endl;
    return;
  }
  --_energy_points;
  std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
            << this->getAttackDamage() << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
  if (_hit_points == 0) {
    std::cout << "ScavTrap " << _name << " has already died." << std::endl;
    return;
  }
  _hit_points = std::max((int)(_hit_points - amount), 0);
  std::cout << "ScavTrap " << _name << " took " << amount << " damages."
            << std::endl;
  if (_hit_points <= 0)
    std::cout << "ScavTrap " << _name << " is died." << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
  if (_energy_points == 0) {
    std::cout << "ScavTrap can't repair because of lack of energy points."
              << std::endl;
    return;
  }
  if (_hit_points == 0) {
    std::cout << "ScavTrap can't repair because it has died." << std::endl;
    return;
  }
  _hit_points = std::min(_hit_points + amount, Limits::MAX_HP);
  --_energy_points;
  std::cout << "ScavTrap " << _name << " repaired " << amount << " hit points."
            << std::endl;
}

void ScavTrap::guardGate() {
  if (_energy_points == 0) {
    std::cout << "ScavTrap can't switch to Gate keeper mode because of lack of "
                 "energy points."
              << std::endl;
    return;
  }
  if (_hit_points == 0) {
    std::cout
        << "ScavTrap can't switch to Gate keeper mode because it has died."
        << std::endl;
    return;
  }

  std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode."
            << std::endl;
}
// ===========================================================
