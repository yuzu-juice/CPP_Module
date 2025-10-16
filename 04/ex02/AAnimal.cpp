#include "AAnimal.hpp"

#include <iostream>

// Constructor================================================
AAnimal::AAnimal() {
  std::cout << "AAnimal default constructor called." << std::endl;
}

AAnimal::AAnimal(const std::string& t) : type(t) {
  std::cout << "AAnimal constructor with string called." << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type) {
  std::cout << "AAnimal copy constructor called." << std::endl;
}
// ===========================================================

// Copy assignment operator overload==========================
AAnimal& AAnimal::operator=(const AAnimal& other) {
  std::cout << "AAnimal copy assignment operator called." << std::endl;
  if (this != &other) {
    type = other.type;
  }
  return *this;
}
// ===========================================================

// Destructor=================================================
AAnimal::~AAnimal() { std::cout << "AAnimal destructor called." << std::endl; }
// ===========================================================

// Getter=====================================================
std::string AAnimal::getType() const { return type; }
// ===========================================================
