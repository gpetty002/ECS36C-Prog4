#include <iostream>
#include <fstream>
#include "huffman.h"

int main(int argc, char *argv[]) {
  if (argc < 3) {
      std::cerr <<
        "Usage: " <<
        argv[0] <<
        " <zapfile> <outputfile>"
        << std::endl;
    return 1;
  }

  std::string input_file_name = argv[1];
  std::string output_file_name = argv[2];

  std::ifstream ifs(input_file_name, 
                    std::ios::out |
                    std::ios::trunc |
                    std::ios::binary);
  std::ofstream ofs(output_file_name, 
                    std::ios::out |
                    std::ios::trunc);

  if (!ifs) {
    std::cerr << "Error: cannot open input file " << input_file_name << std::endl;
    return 1;
  }


  BinaryOutputStream bos(ofs);
  
  return 0;
}
