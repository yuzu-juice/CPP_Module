#include "Ice.hpp"

#include <iostream>

// Constructor================================================
Ice::Ice() {
  std::cout << "Ice default constructor called." << std::endl;
  _type = "ice";
}

Ice::Ice(const Ice& other) : AMateria(other) {
  std::cout << "Ice copy constructor called." << std::endl;
}
// ===========================================================

// Copy assignment operator overload==========================
Ice& Ice::operator=(const Ice& other) {
  std::cout << "Ice copy assignment operator called." << std::endl;
  if (this != &other) {
    AMateria::operator=(other);
  }
  return *this;
}
// ===========================================================

// Destructor=================================================
Ice::~Ice() { std::cout << "Ice destructor called." << std::endl; }
// ===========================================================

// Method=====================================================
AMateria* Ice::clone() const { return new Ice(); }

void Ice::use(ICharacter& c) {
  std::cout << "* heals " << c.getName() << "'s wounds *" << std::endl;
}
// ===========================================================
