#include "Dog.hpp"

#include <iostream>

// Constructor================================================
Dog::Dog() : AAnimal("Dog") {
  std::cout << "Dog default constructor called." << std::endl;
  _brain = new Brain();
}

Dog::Dog(const Dog& other) : AAnimal(other) {
  std::cout << "Dog copy constructor called." << std::endl;
  _brain = new Brain(*other._brain);
}
// ===========================================================

// Copy assignment operator overload==========================
Dog& Dog::operator=(const Dog& other) {
  std::cout << "Dog copy assignment operator called." << std::endl;
  if (this != &other) {
    AAnimal::operator=(other);
    delete _brain;
    _brain = new Brain(*other._brain);
  }
  return *this;
}
// ===========================================================

// Destructor=================================================
Dog::~Dog() {
  std::cout << "Dog destructor called." << std::endl;
  delete _brain;
}
// ===========================================================

// Method=====================================================
void Dog::makeSound() const { std::cout << "Woof" << std::endl; }

Brain* Dog::getBrain() const { return _brain; }
// ===========================================================
