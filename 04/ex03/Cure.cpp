#include "Cure.hpp"

#include <iostream>

// Constructor================================================
Cure::Cure() {
  std::cout << "Cure default constructor called." << std::endl;
  _type = "cure";
}

Cure::Cure(const Cure& other) : AMateria(other) {
  std::cout << "Cure copy constructor called." << std::endl;
}
// ===========================================================

// Copy assignment operator overload==========================
Cure& Cure::operator=(const Cure& other) {
  std::cout << "Cure copy assignment operator called." << std::endl;
  if (this != &other) {
    AMateria::operator=(other);
  }
  return *this;
}
// ===========================================================

// Destructor=================================================
Cure::~Cure() { std::cout << "Cure destructor called." << std::endl; }
// ===========================================================

// Method=====================================================
AMateria* Cure::clone() const { return new Cure(); }

void Cure::use(ICharacter& c) {
  std::cout << "* shoots an ice bolt at " << c.getName() << " *" << std::endl;
}
// ===========================================================
