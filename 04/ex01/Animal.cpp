#include "Animal.hpp"

#include <iostream>

// Constructor================================================
Animal::Animal() {
  std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(const std::string& t) : type(t) {
  std::cout << "Animal constructor with string called." << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
  std::cout << "Animal copy constructor called." << std::endl;
}
// ===========================================================

// Copy assignment operator overload==========================
Animal& Animal::operator=(const Animal& other) {
  std::cout << "Animal copy assignment operator called." << std::endl;
  if (this != &other) {
    type = other.type;
  }
  return *this;
}
// ===========================================================

// Destructor=================================================
Animal::~Animal() { std::cout << "Animal destructor called." << std::endl; }
// ===========================================================

// Getter=====================================================
std::string Animal::getType() const { return type; }
// ===========================================================

// Method=====================================================
void Animal::makeSound() const { std::cout << "..." << std::endl; }
// ===========================================================
