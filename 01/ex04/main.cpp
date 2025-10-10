#include <fstream>
#include <iostream>

#include "printError.hpp"

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printError(argc_error);
    return 1;
  }

  std::ifstream infile(argv[1]);
  std::string s1(argv[2]);
  std::string s2(argv[3]);

  if (!infile) {
    printError(fail_to_open_infile);
    return 1;
  }

  std::string content((std::istreambuf_iterator<char>(infile)),
                      std::istreambuf_iterator<char>());
  infile.close();

  std::string::size_type pos = content.find(s1);
  while (pos != std::string::npos) {
    content.erase(pos, s1.length());
    content.insert(pos, s2);
    pos = content.find(s1, pos + s2.length());
  }

  std::string outFilename = std::string(argv[1]) + ".replace";
  std::ofstream outfile(outFilename.c_str());

  if (!outfile) {
    printError(fail_to_open_outfile);
    return 1;
  }

  outfile << content;
  outfile.close();
}
