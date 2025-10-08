#ifndef CONTACT_CLASS_H_
#define CONTACT_CLASS_H_
#include <string>
class Contact {
 public:
  Contact(void);
  ~Contact(void);

  std::string getFirstName() const;
  void setFirstName(std::string);

  std::string getLastName() const;
  void setLastName(std::string);

  std::string getNickname() const;
  void setNickname(std::string);

  std::string getPhoneNumber() const;
  void setPhoneNumber(std::string);

  std::string getDarkestSecret() const;
  void setDarkestSecret(std::string);

 private:
  std::string _first_name;
  std::string _last_name;
  std::string _nickname;
  std::string _phone_number;
  std::string _darkest_secret;
};
#endif
