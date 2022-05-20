#ifndef HUFFMAN_H_
#define HUFFMAN_H_

#include <array>
#include <cstddef>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "bstream.h"
#include "pqueue.h"

#define ASCII_CHARS 256

class HuffmanNode {
 public:
  explicit HuffmanNode(char ch, size_t freq,
                       HuffmanNode *left = nullptr,
                       HuffmanNode *right = nullptr)
      : ch_(ch), freq_(freq), left_(left), right_(right) { }


  bool IsLeaf() {
    // Node is a leaf if it doesn't have any children
    return left_ == nullptr && right_ == nullptr;
  }

  bool operator < (const HuffmanNode &n) const {
    // In case of equality, make it deterministic based on character
    if (freq_ == n.freq_)
      return ch_ < n.ch_;
    // Otherwise compare frequencies
    return freq_ < n.freq_;
  }

  size_t freq() { return freq_; }
  size_t data() { return ch_; }
  HuffmanNode* left() { return left_; }
  HuffmanNode* right() { return right_; }

 private:
  char ch_;
  size_t freq_;
  HuffmanNode *left_, *right_;
};

class Huffman {
 public:
  static void Compress(std::ifstream &ifs, std::ofstream &ofs);

  static void Decompress(std::ifstream &ifs, std::ofstream &ofs);

 private:
  // Helper methods...
};

// To be completed below

void Huffman::Compress(std::ifstream &ifs, std::ofstream &ofs) {
  char c;
  std::array<int, ASCII_CHARS> ascii;
  std::string chars_to_read = "";
  BinaryInputStream bis(ifs);

  for (int i = 0; i < ASCII_CHARS; i++) {
    ascii[i] = 0;
  }

  try
  {
    while (1) {
      c = bis.GetChar();
      if (ascii[c] == 0) {
        chars_to_read += c;
      }
      ascii[c]++;
    }
  }
  catch(std::exception& e)
  {
    if (chars_to_read == "") {
      std::cout << e.what() << std::endl;
      return;
    }
  }
  ifs.close();
  PQueue<HuffmanNode*> huff_tree;

  for (auto j : chars_to_read) {
    huff_tree.Push(new HuffmanNode(chars_to_read[j], ascii[chars_to_read[j]], nullptr, nullptr));
  }
  std::cout << "Huff Tree Top: \'" << huff_tree.Top()->data() << "\' has frequency " <<
                  huff_tree.Top()->freq() << std::endl;

  ofs.close();
}

void Huffman::Decompress(std::ifstream &ifs, std::ofstream &ofs) {

}

#endif  // HUFFMAN_H_
