#include "ClapTrap.hpp"

#include <iostream>

// Constructor================================================
ClapTrap::ClapTrap() : _hit_points(10), _energy_points(10), _attack_damage(0) {
  std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
  std::cout << "ClapTrap constructor called with string." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : _name(other._name),
      _hit_points(other._hit_points),
      _energy_points(other._energy_points),
      _attack_damage(other._attack_damage) {
  std::cout << "ClapTrap copy constructor called." << std::endl;
}
// ===========================================================

// Destructor=================================================
ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap destructor called." << std::endl;
}
// ===========================================================

// Copy assignment operator overload==========================
ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  std::cout << "ClapTrap copy assignment operator called." << std::endl;
  if (this != &other) {
    _name = other._name;
    _hit_points = other._hit_points;
    _energy_points = other._energy_points;
    _attack_damage = other._attack_damage;
  }
  return *this;
}
// ===========================================================

// Getter=====================================================
int ClapTrap::getHitPoints() const { return this->_hit_points; }

int ClapTrap::getEnergyPoints() const { return this->_energy_points; }

int ClapTrap::getAttackDamage() const { return this->_attack_damage; }
// ===========================================================

// Method=====================================================
void ClapTrap::attack(const std::string &target) {
  if (_energy_points <= 0) {
    std::cout << "ClapTrap can't attack because of lack of energy points."
              << std::endl;
    return;
  }
  --_energy_points;
  std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
            << this->getAttackDamage() << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (this->getHitPoints() <= 0) {
    std::cout << "ClapTrap " << _name << " has already died." << std::endl;
    return;
  }
  _hit_points -= amount;
  std::cout << "ClapTrap " << _name << " took " << amount << " damages."
            << std::endl;
  if (_hit_points <= 0)
    std::cout << "ClapTrap " << _name << " is died." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_energy_points <= 0) {
    std::cout << "ClapTrap can't repair because of lack of energy points."
              << std::endl;
    return;
  }
  _hit_points += amount;
  --_energy_points;
  std::cout << "ClapTrap " << _name << " repaired " << amount << " hit points."
            << std::endl;
}
// ===========================================================
