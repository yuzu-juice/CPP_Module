#ifndef BRAIN_HPP_
#define BRAIN_HPP_

#include <string>

class Brain {
 public:
  Brain();
  Brain(const Brain&);
  Brain& operator=(const Brain&);
  ~Brain();

  void setIdea(size_t, std::string);
  std::string getIdea(size_t);

 private:
  std::string _ideas[100];
};

#endif
