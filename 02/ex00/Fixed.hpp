#ifndef FIXED_HPP_
#define FIXED_HPP_

class Fixed {
 public:
  Fixed();
  Fixed(const Fixed &);
  Fixed &operator=(const Fixed &);
  ~Fixed();

 private:
  int value;
  static const int bits = 8;
};

#endif
