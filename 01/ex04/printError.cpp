#include "printError.hpp"

#include <iostream>

void printError(ErrorType e) {
  if (e == argc_error)
    std::cerr << "usage: ./replace [filename] [string1] [string2]" << std::endl;
  else if (e == fail_to_open_infile)
    std::cerr << "Cannot open the infile." << std::endl;
  else if (e == fail_to_open_outfile)
    std::cerr << "Cannot open the out file." << std::endl;
}
