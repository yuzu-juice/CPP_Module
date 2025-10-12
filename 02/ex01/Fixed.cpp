#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed() : value(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : value(other.value) {
  std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int i) {
  std::cout << "Int constructor called" << std::endl;
  this->setRawBits(i << this->fraction_bits);
}

Fixed::Fixed(const float i) {
  std::cout << "Float constructor called" << std::endl;
  this->setRawBits(i * 256);
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) this->setRawBits(other.getRawBits());
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits() const { return this->value; }

void Fixed::setRawBits(int const raw) { this->value = raw; }

float Fixed::toFloat() const {
  int rawBits = this->getRawBits();
  int i = rawBits >> this->fraction_bits;
  int frac = rawBits & 0b111;
  float ret = i + frac / 10;
  return ret;
}

int Fixed::toInt() const {
  int raw = this->getRawBits();
  return raw >> this->fraction_bits;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
  os << fixed.toFloat();
  return os;
}
