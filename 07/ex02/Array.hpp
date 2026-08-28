#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <stdexcept>

template <typename T>
class Array {
 public:
  Array();
  explicit Array(unsigned int size);
  Array(const Array& other);
  Array& operator=(const Array& other);
  ~Array();

  T& operator[](unsigned int index);
  const T& operator[](unsigned int index) const;

  unsigned int size() const;

 private:
  T* data_;
  unsigned int size_;
};

#include "Array.tpp"

#endif
