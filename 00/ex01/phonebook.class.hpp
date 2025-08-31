#ifndef PHONEBOOK_CLASS_H_
#define PHONEBOOK_CLASS_H_

#include <array>

#include "contact.class.hpp"

class PhoneBook {
 public:
  PhoneBook(void);
  ~PhoneBook(void);
  void addContact(Contact contact);
  std::array<Contact, 8> getAllContacts() const;
  void displayAllConacts(std::array<Contact, 8>) const;
  size_t getPhoneBookSize() const;

 private:
  std::array<Contact, 8> _array;
  int _last_index = 0;
};

#endif
