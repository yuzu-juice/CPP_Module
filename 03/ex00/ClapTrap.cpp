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
ClapTrap::~ClapTrap() { std::cout << "Destructor called." << std::endl; }
// ===========================================================

// Copy assignment operator overload==========================
ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  std::cout << "ClapTrap copy assignment operator called." << std::endl;
  if (this != &other) {
    this->setName(other.getName());
    this->setHitPoints(other.getHitPoints());
    this->setEnergyPoints(other.getEnergyPoints());
    this->setAttackDamage(other.getAttackDamage());
  }
  return *this;
}
// ===========================================================

// Setter=====================================================
void ClapTrap::setName(std::string name) { this->_name = name; }

void ClapTrap::setHitPoints(int hit_points) { this->_hit_points = hit_points; }

void ClapTrap::setEnergyPoints(int energy_points) {
  this->_energy_points = energy_points;
}

void ClapTrap::setAttackDamage(int attack_damage) {
  this->_attack_damage = attack_damage;
}
// ===========================================================

// Getter=====================================================
std::string ClapTrap::getName() const { return this->_name; }

int ClapTrap::getHitPoints() const { return this->_hit_points; }

int ClapTrap::getEnergyPoints() const { return this->_energy_points; }

int ClapTrap::getAttackDamage() const { return this->_attack_damage; }
// ===========================================================

// Method=====================================================
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

void ClapTrap::takeDamage(unsigned int amount) {
  if (this->getHitPoints() <= 0) {
    std::cout << "ClapTrap " << this->_name << " has already died."
              << std::endl;
    return;
  }
  this->setHitPoints(this->getHitPoints() - amount);
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
// ===========================================================
