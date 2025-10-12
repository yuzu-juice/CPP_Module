#ifndef FIXED_HPP_
#define FIXED_HPP_

class Fixed {
 public:
  Fixed();
  Fixed(const Fixed &);
  Fixed &operator=(const Fixed &);
  ~Fixed();
  int getRawBits() const;
  void setRawBits(int const);

 private:
  int value;
  static const int fraction_bits = 8;
};

#endif
