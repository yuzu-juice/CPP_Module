#ifndef PHONEBOOK_CLASS_H_
#define PHONEBOOK_CLASS_H_

#include <array>

#include "contact.class.hpp"

class PhoneBook {
 public:
  PhoneBook(void);
  ~PhoneBook(void);
  void addContact(Contact);
  std::array<Contact, 8> getAllContacts(void) const;
  Contact getContact(size_t) const;
  void displayContact(Contact) const;
  void displayAllContacts(std::array<Contact, 8>) const;
  size_t getPhoneBookSize(void) const;

 private:
  std::string format(std::string) const;
  std::array<Contact, 8> _array;
  int _last_index = 0;
};

#endif
