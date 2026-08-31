#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int value) {
  return std::find(container.begin(), container.end(), value);
}
