#ifndef ITER_HPP_
#define ITER_HPP_

#include <cstddef>

template <typename T, typename F>
void iter(T* array, const std::size_t length, F function) {
  for (std::size_t i = 0; i < length; ++i) {
    function(array[i]);
  }
}

#endif
