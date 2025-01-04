#include "naive.h" // Ensure naive.h is included
#include <iostream>
#include <fstream>
#include <ctime> // For time()

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "use by -> ./naive_wordrange <input file> <output file>\n";
        return 1;
    }

    std::ifstream input_file(argv[1]);
    std::ofstream output_file(argv[2]);

    if (!input_file.is_open() || !output_file.is_open())
    {
        std::cerr << "ERR OPENING EITHER INPUT OR OUTPUT FILE\n";
        return 1;
    }

    BST tree; // Ensure this matches the BST class in naive.h
    std::string cmnd;

    while (input_file >> cmnd)
    {
        if (cmnd == "i")
        {
            std::string word;
            input_file >> word;
            tree.insert(word); // Insert a word into the BST
        }
        else if (cmnd == "r")
        {
            std::string low, high;
            input_file >> low >> high;

            output_file << tree.range_query(low, high) << "\n"; // Perform a range query
        }
    }

    input_file.close();
    output_file.close();

    // Add a 30-second delay using time()
    std::cout << "Program complete. Pausing for 30 seconds to allow memory monitoring..." << std::endl;
    time_t start_time = time(nullptr); // Get the current time
    while (time(nullptr) - start_time < 30)
    {
        // Busy-wait for 30 seconds
    }

    return 0;
}
