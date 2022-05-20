#include <iostream>
#include <fstream>
#include <array>

//#include "huffman.h"
#include "bstream.h" // remove later

int main(int argc, char** argv) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] <<
    " <input file> <zap file>" << std::endl;
    exit(1);
  }
  std::string inputfile = argv[1];
  std::string zapfile = argv[2];
  std::string chars_to_read;
  char c;

  std::ifstream ifs(inputfile, std::ios::in);
  std::array<int, 256> ascii;

  for (int i = 0; i < 256; ++i) {
    ascii[i] = 0;
  }

  while (ifs >> c) {
    ascii[c]++;
    chars_to_read += c;
  }
  
  ifs.close();

  for (int i = 0; i < 256; ++i) {
    if (ascii[i] != 0) {
      std::cout << ascii[i] << std::endl;
    }
  }
  std::cout << chars_to_read << std::endl;
  return 0;
}
