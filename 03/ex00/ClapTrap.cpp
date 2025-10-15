#include "ClapTrap.hpp"

#include <algorithm>
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

// Setter=====================================================
void ClapTrap::setName(const std::string &name) { _name = name; }

void ClapTrap::setHitPoints(const unsigned int hit_points) {
  _hit_points = std::min(hit_points, Limits::MAX_HP);
}

void ClapTrap::setEnergyPoints(const unsigned int energy_points) {
  _energy_points = std::min(energy_points, Limits::MAX_EP);
}

void ClapTrap::setAttackDamage(const unsigned int attack_damage) {
  _attack_damage = std::min(attack_damage, Limits::MAX_DAMAGE);
}
// ===========================================================

// Getter=====================================================
std::string ClapTrap::getName() const { return _name; }

unsigned int ClapTrap::getHitPoints() const { return _hit_points; }

unsigned int ClapTrap::getEnergyPoints() const { return _energy_points; }

unsigned int ClapTrap::getAttackDamage() const { return _attack_damage; }
// ===========================================================

// Method=====================================================
void ClapTrap::attack(const std::string &target) {
  if (_energy_points == 0) {
    std::cout << "ClapTrap can't attack because of lack of energy points."
              << std::endl;
    return;
  }
  if (_hit_points == 0) {
    std::cout << "ClapTrap can't attack because it has died." << std::endl;
    return;
  }
  --_energy_points;
  std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
            << this->getAttackDamage() << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_hit_points <= 0) {
    std::cout << "ClapTrap " << _name << " has already died." << std::endl;
    return;
  }
  if (_hit_points < amount)
    _hit_points = 0;
  else
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
  if (_hit_points <= 0) {
    std::cout << "ClapTrap can't repair because it has died." << std::endl;
    return;
  }
  _hit_points = std::min(_hit_points + amount, Limits::MAX_HP);
  --_energy_points;
  std::cout << "ClapTrap " << _name << " repaired " << amount << " hit points."
            << std::endl;
}
// ===========================================================
