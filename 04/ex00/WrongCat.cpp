#include "WrongCat.hpp"

#include <iostream>

// Constructor================================================
WrongCat::WrongCat() : WrongAnimal("Cat") {
  std::cout << "WrongCat default constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
  std::cout << "WrongCat copy constructor called." << std::endl;
}
// ===========================================================

// Copy assignment operator overload==========================
WrongCat &WrongCat::operator=(const WrongCat &other) {
  std::cout << "WrongCat copy assignment operator called." << std::endl;
  if (this != &other) {
    type = other.type;
  }
  return *this;
}
// ===========================================================

// Destructor=================================================
WrongCat::~WrongCat() {
  std::cout << "WrongCat destructor called." << std::endl;
}
// ===========================================================

// Method=====================================================
void WrongCat::makeSound() const { std::cout << "Mrrr" << std::endl; }
// ===========================================================
