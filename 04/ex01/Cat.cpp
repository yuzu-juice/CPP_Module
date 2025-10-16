#include "Cat.hpp"

#include <iostream>

// Constructor================================================
Cat::Cat() : Animal("Cat") {
  std::cout << "Cat default constructor called." << std::endl;
  _brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other) {
  std::cout << "Cat copy constructor called." << std::endl;
  _brain = new Brain(*other._brain);
}
// ===========================================================

// Copy assignment operator overload==========================
Cat& Cat::operator=(const Cat& other) {
  std::cout << "Cat copy assignment operator called." << std::endl;
  Animal::operator=(other);
  delete _brain;
  _brain = new Brain(*other._brain);
  return *this;
}
// ===========================================================

// Destructor=================================================
Cat::~Cat() {
  std::cout << "Cat destructor called." << std::endl;
  delete _brain;
}
// ===========================================================

// Method=====================================================
void Cat::makeSound() const { std::cout << "Mrrr" << std::endl; }

Brain* Cat::getBrain() const { return _brain; }
// ===========================================================
