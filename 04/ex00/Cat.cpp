#include "Cat.hpp"

#include <iostream>

// Constructor================================================
Cat::Cat() : Animal("Cat") {
  std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
  std::cout << "Cat copy constructor called." << std::endl;
}
// ===========================================================

// Copy assignment operator overload==========================
Cat &Cat::operator=(const Cat &other) {
  std::cout << "Cat copy assignment operator called." << std::endl;
  if (this != &other) {
    type = other.type;
  }
  return *this;
}
// ===========================================================

// Destructor=================================================
Cat::~Cat() { std::cout << "Cat destructor called." << std::endl; }
// ===========================================================

// Method=====================================================
void Cat::makeSound() const { std::cout << "Mrrr" << std::endl; }
// ===========================================================
