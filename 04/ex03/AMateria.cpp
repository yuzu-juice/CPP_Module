#include "AMateria.hpp"

#include <iostream>

// Constructor================================================
AMateria::AMateria() {
  std::cout << "AMateria default constructor called." << std::endl;
}

AMateria::AMateria(std::string const& type) : _type(type) {
  std::cout << "AMateria constructor called with string." << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
  std::cout << "AMateria copy constructor called." << std::endl;
}
// ===========================================================

// Copy assignment operator overload==========================
AMateria& AMateria::operator=(const AMateria& other) {
  std::cout << "AMateria copy assignment operator called." << std::endl;
  if (this != &other) {
    _type = other._type;
  }
  return *this;
}
// ===========================================================

// Destructor=================================================
AMateria::~AMateria() {
  std::cout << "AMateria destructor called." << std::endl;
}
// ===========================================================

// Getter=====================================================
std::string const& AMateria::getType() const { return _type; }
// ===========================================================
