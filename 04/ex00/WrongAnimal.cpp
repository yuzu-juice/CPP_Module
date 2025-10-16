#include "WrongAnimal.hpp"

#include <iostream>

// Constructor================================================
WrongAnimal::WrongAnimal() {
  std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& t) : type(t) {
  std::cout << "WrongAnimal constructor with string called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
  std::cout << "WrongAnimal copy constructor called." << std::endl;
}
// ===========================================================

// Copy assignment operator overload==========================
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
  std::cout << "WrongAnimal copy assignment operator called." << std::endl;
  if (this != &other) {
    type = other.type;
  }
  return *this;
}
// ===========================================================

// Destructor=================================================
WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor called." << std::endl;
}
// ===========================================================

// Getter=====================================================
std::string WrongAnimal::getType() const { return type; }
// ===========================================================

// Method=====================================================
void WrongAnimal::makeSound() const { std::cout << "..." << std::endl; }
// ===========================================================
