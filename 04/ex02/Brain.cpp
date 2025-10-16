#include "Brain.hpp"

#include <iostream>

// Constructor================================================
Brain::Brain() {
  std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain& other) {
  std::cout << "Brain copy constructor called." << std::endl;
  for (int i = 0; i < 100; ++i) {
    _ideas[i] = other._ideas[i];
  }
}
// ===========================================================

// Copy assignment operator overload==========================
Brain& Brain::operator=(const Brain& other) {
  std::cout << "Brain copy assignment operator called." << std::endl;
  if (this != &other) {
    for (int i = 0; i < 100; ++i) {
      _ideas[i] = other._ideas[i];
    }
  }
  return *this;
}
// ===========================================================

// Destructor=================================================
Brain::~Brain() { std::cout << "Brain destructor called." << std::endl; }
// ===========================================================

// Method=====================================================
void Brain::setIdea(size_t i, std::string idea) {
  if (i >= 100) return;
  _ideas[i] = idea;
}

std::string Brain::getIdea(size_t i) {
  if (i >= 100) return "";
  return _ideas[i];
}
// ===========================================================
