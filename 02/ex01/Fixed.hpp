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
