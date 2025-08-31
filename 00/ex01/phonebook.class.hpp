#ifndef PHONEBOOK_CLASS_H_
#define PHONEBOOK_CLASS_H_

#include <queue>

#include "contact.class.hpp"

class PhoneBook {
 public:
  PhoneBook(void);
  ~PhoneBook(void);
  void Add(Contact contact);
  size_t ListSize();

 private:
  std::queue<Contact> _que;
};

#endif