#include <iostream>

#include "Data.hpp"
#include "Serializer.hpp"

int main() {
  Data data;
  data.number = 42;
  data.text = "CPP Module 06";

  const uintptr_t raw = Serializer::serialize(&data);
  Data* restored = Serializer::deserialize(raw);

  std::cout << "original: " << &data << "\n";
  std::cout << "restored: " << restored << "\n";

  if (restored != &data) {
    std::cerr << "Serialization failed\n";
    return 1;
  }

  std::cout << "same pointer: yes\n";
  std::cout << "data: " << restored->number << ", " << restored->text << "\n";
  return 0;
}
