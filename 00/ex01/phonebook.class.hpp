#ifndef PHONEBOOK_CLASS_H_
#define PHONEBOOK_CLASS_H_

#include <array>

#include "contact.class.hpp"

class PhoneBook {
 public:
  PhoneBook(void);
  ~PhoneBook(void);
  void addContact(Contact);
  const Contact (&getAllContacts() const)[8];
  Contact getContact(size_t) const;
  void displayContact(Contact) const;
  void displayAllContacts(const Contact*) const;
  size_t getPhoneBookSize(void) const;

 private:
  std::string format(std::string) const;
  Contact _array[8];
  int _last_index;
};

#endif
