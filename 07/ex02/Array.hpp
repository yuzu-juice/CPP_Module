#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <stdexcept>

template <typename T>
class Array {
 public:
  Array() : data_(0), size_(0) {}

  explicit Array(unsigned int size)
      : data_(size == 0 ? 0 : new T[size]()), size_(size) {}

  Array(const Array& other)
      : data_(other.size_ == 0 ? 0 : new T[other.size_]()), size_(other.size_) {
    try {
      for (unsigned int i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
      }
    } catch (...) {
      delete[] data_;
      throw;
    }
  }

  Array& operator=(const Array& other) {
    if (this != &other) {
      Array copy(other);

      T* old_data = data_;
      data_ = copy.data_;
      copy.data_ = old_data;

      unsigned int old_size = size_;
      size_ = copy.size_;
      copy.size_ = old_size;
    }
    return *this;
  }

  ~Array() { delete[] data_; }

  T& operator[](unsigned int index) {
    if (index >= size_) {
      throw std::out_of_range("Array index out of bounds");
    }
    return data_[index];
  }

  const T& operator[](unsigned int index) const {
    if (index >= size_) {
      throw std::out_of_range("Array index out of bounds");
    }
    return data_[index];
  }

  unsigned int size() const { return size_; }

 private:
  T* data_;
  unsigned int size_;
};

#endif
