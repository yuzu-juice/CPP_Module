#include "FragTrap.hpp"

#include <iostream>

#include "ClapTrap.hpp"

// Constructor================================================
FragTrap::FragTrap() {
  std::cout << "FragTrap default constructor called." << std::endl;
  _hit_points = 100;
  _energy_points = 100;
  _attack_damage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
  std::cout << "FragTrap constructor called with string." << std::endl;
  _hit_points = 100;
  _energy_points = 100;
  _attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
  std::cout << "FragTrap copy constructor called." << std::endl;
}
// ===========================================================

// Destructor=================================================
FragTrap::~FragTrap() {
  std::cout << "FragTrap destructor called." << std::endl;
}
// ===========================================================

// Copy assignment operator overload==========================
FragTrap& FragTrap::operator=(const FragTrap& other) {
  std::cout << "FragTrap copy assignment operator called." << std::endl;
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
void FragTrap::attack(const std::string& target) {
  if (_energy_points == 0) {
    std::cout << "FragTrap can't attack because of lack of energy points."
              << std::endl;
    return;
  }
  if (_hit_points == 0) {
    std::cout << "FragTrap can't attack because it has died." << std::endl;
    return;
  }
  --_energy_points;
  std::cout << "FragTrap " << _name << " attacks " << target << ", causing "
            << this->getAttackDamage() << " points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
  if (_hit_points == 0) {
    std::cout << "FragTrap " << _name << " has already died." << std::endl;
    return;
  }
  _hit_points = std::max((int)(_hit_points - amount), 0);
  std::cout << "FragTrap " << _name << " took " << amount << " damages."
            << std::endl;
  if (_hit_points == 0)
    std::cout << "FragTrap " << _name << " is died." << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
  if (_energy_points == 0) {
    std::cout << "FragTrap can't repair because of lack of energy points."
              << std::endl;
    return;
  }
  if (_hit_points == 0) {
    std::cout << "FragTrap can't repair because it has died." << std::endl;
    return;
  }
  _hit_points = std::min(_hit_points + amount, Limits::MAX_HP);
  --_energy_points;
  std::cout << "FragTrap " << _name << " repaired " << amount << " hit points."
            << std::endl;
}

void FragTrap::highFivesGuys() {
  if (_energy_points == 0) {
    std::cout << "FragTrap can't do high five because of lack of energy points."
              << std::endl;
    return;
  }
  if (_hit_points == 0) {
    std::cout << "FragTrap can't do high five because it has died."
              << std::endl;
    return;
  }
  std::cout << "Give me high five!" << std::endl;
}
// ===========================================================
