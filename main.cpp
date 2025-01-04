#include "avl.h"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    std::cerr << "use by -> ./wordrange <input file> <output file>\n";
    return 1;
  }

  std::ifstream input_file(argv[1]);
  std::ofstream output_file(argv[2]);

  if (!input_file.is_open() || !output_file.is_open())
  {
    std::cerr << "ERR OPENING EITHER INPUT OR OUTPUT FILE\n";
    return 1;
  }

  AVLTree tree;
  std::string cmnd;

  while (input_file >> cmnd)
  {
    if (cmnd == "i")
    {
      std::string word;
      input_file >> word;
      tree.insert(word);
    }
    else if (cmnd == "r")
    {
      std::string low, high;
      input_file >> low >> high;

      output_file << tree.range_query(low, high) << "\n";
    }
  }

  input_file.close();
  output_file.close();

  return 0;
}