#include "Dog.hpp"

#include <iostream>

// Constructor================================================
Dog::Dog() : Animal("Dog") {
  std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << "Dog copy constructor called." << std::endl;
}
// ===========================================================

// Copy assignment operator overload==========================
Dog &Dog::operator=(const Dog &other) {
  std::cout << "Dog copy assignment operator called." << std::endl;
  if (this != &other) {
    type = other.type;
  }
  return *this;
}
// ===========================================================

// Destructor=================================================
Dog::~Dog() { std::cout << "Dog destructor called." << std::endl; }
// ===========================================================

// Method=====================================================
void Dog::makeSound() const { std::cout << "Woof" << std::endl; }
// ===========================================================
