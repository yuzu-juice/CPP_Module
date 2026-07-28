#ifndef SERIALIZER_HPP_
#define SERIALIZER_HPP_

#include <stdint.h>

#include "Data.hpp"

class Serializer {
 public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);

 private:
  Serializer();
  Serializer(const Serializer& other);
  Serializer& operator=(const Serializer& other);
  ~Serializer();
};

#endif
