#ifndef FIXED_HPP_
#define FIXED_HPP_

#include <ostream>

class Fixed {
 public:
  Fixed();
  Fixed(const Fixed &);
  Fixed(const int);
  Fixed(const float);
  ~Fixed();

  Fixed &operator=(const Fixed &);

  // Comparison operators
  bool operator>(const Fixed &);
  bool operator<(const Fixed &);
  bool operator>=(const Fixed &);
  bool operator<=(const Fixed &);
  bool operator==(const Fixed &);
  bool operator!=(const Fixed &);

  // Arithmetic oprators
  Fixed operator+(const Fixed &) const;
  Fixed operator-(const Fixed &) const;
  Fixed operator*(const Fixed &) const;
  Fixed operator/(const Fixed &) const;

  // Prefix increment operator
  Fixed &operator++();
  // Postfix increment oprator
  Fixed operator++(int);
  // Prefix decrement operator
  Fixed &operator--();
  // Postfix decrement oprator
  Fixed operator--(int);

  static Fixed &min(Fixed &fixed1, Fixed &fixed2);
  static const Fixed &min(const Fixed &fixed1, const Fixed &fixed2);
  static Fixed &max(Fixed &fixed1, Fixed &fixed2);
  static const Fixed &max(const Fixed &fixed1, const Fixed &fixed2);

  int getRawBits() const;
  void setRawBits(int const);
  float toFloat() const;
  int toInt() const;

 private:
  int value;
  static const int fraction_bits = 8;
};

std::ostream &operator<<(std::ostream &, const Fixed &);

#endif
