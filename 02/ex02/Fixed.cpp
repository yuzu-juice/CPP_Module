#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const Fixed &other) : value(other.value) {}

Fixed::Fixed(const int i) { this->setRawBits(i << this->fraction_bits); }

Fixed::Fixed(const float i) {
  this->setRawBits(static_cast<int>(roundf(i * (1 << this->fraction_bits))));
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &other) {
  if (this != &other) this->setRawBits(other.getRawBits());
  return *this;
}

bool Fixed::operator>(const Fixed &other) { return this->value > other.value; }

bool Fixed::operator<(const Fixed &other) { return this->value < other.value; }

bool Fixed::operator>=(const Fixed &other) {
  return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed &other) {
  return this->value <= other.value;
}

bool Fixed::operator==(const Fixed &other) {
  return this->value == other.value;
}

bool Fixed::operator!=(const Fixed &other) {
  return this->value != other.value;
}

Fixed Fixed::operator+(const Fixed &other) const {
  Fixed result = Fixed(this->toFloat() + other.toFloat());

  return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
  Fixed result = Fixed(this->toFloat() - other.toFloat());

  return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
  Fixed result = Fixed(this->toFloat() * other.toFloat());

  return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
  Fixed result = Fixed(this->toFloat() / other.toFloat());

  return result;
}

Fixed &Fixed::operator++() {
  this->value++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp = *this;
  ++*this;
  return tmp;
}

Fixed &Fixed::operator--() {
  this->value--;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed tmp = *this;
  --*this;
  return tmp;
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2) {
  if (fixed1.value < fixed2.value) return fixed1;
  return fixed2;
}

const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2) {
  if (fixed1.value < fixed2.value) return fixed1;
  return fixed2;
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2) {
  if (fixed1.value >= fixed2.value) return fixed1;
  return fixed2;
}

const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2) {
  if (fixed1.value >= fixed2.value) return fixed1;
  return fixed2;
}

int Fixed::getRawBits() const { return this->value; }

void Fixed::setRawBits(int const raw) { this->value = raw; }

float Fixed::toFloat() const {
  return (float)this->getRawBits() / (1 << this->fraction_bits);
}

int Fixed::toInt() const {
  int raw = this->getRawBits();
  return raw >> this->fraction_bits;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
  os << fixed.toFloat();
  return os;
}
