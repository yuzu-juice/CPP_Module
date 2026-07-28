#ifndef WHATEVER_HPP_
#define WHATEVER_HPP_

template <typename T>
void swap(T& first, T& second) {
  T temporary = first;
  first = second;
  second = temporary;
}

template <typename T>
const T& min(const T& first, const T& second) {
  return first < second ? first : second;
}

template <typename T>
const T& max(const T& first, const T& second) {
  return first > second ? first : second;
}

#endif
