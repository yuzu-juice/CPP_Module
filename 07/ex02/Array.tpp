template <typename T>
Array<T>::Array() : data_(0), size_(0) {}

template <typename T>
Array<T>::Array(unsigned int size)
    : data_(size == 0 ? 0 : new T[size]()), size_(size) {}

template <typename T>
Array<T>::Array(const Array& other)
    : data_(other.size_ == 0 ? 0 : new T[other.size_]()), size_(other.size_) {
    for (unsigned int i = 0; i < size_; ++i)
      data_[i] = other.data_[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
  if (this == &other)
    return *this;

  delete[] data_;
  size_ = other.size_;
  data_ = size_ == 0 ? 0 : new T[size_]();
  for (unsigned int i = 0; i < size_; ++i)
    data_[i] = other.data_[i];

  return *this;
}

template <typename T>
Array<T>::~Array() {
  delete[] data_;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
  if (index >= size_) {
    throw std::out_of_range("Array index out of bounds");
  }
  return data_[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
  if (index >= size_) {
    throw std::out_of_range("Array index out of bounds");
  }
  return data_[index];
}

template <typename T>
unsigned int Array<T>::size() const {
  return size_;
}
