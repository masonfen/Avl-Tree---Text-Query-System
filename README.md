# Avl-Tree---Text-Query-System

## Overview
This program implements an **AVL tree** for managing a collection of words. It supports:
- **Insertions**: Add unique words into the tree.
- **Range Queries**: Efficiently query the number of words within a specified lexicographical range.

The program is optimized to handle up to a million insertions and two million range queries efficiently, leveraging the self-balancing properties of AVL trees.

---

## Features
- **Efficient Operations**:
  - AVL Tree ensures logarithmic height for quick insertions and lookups.
  - Subtree size augmentation enables fast range queries.
- **Modular Codebase**:
  - Separate files for the AVL tree logic, main program, and build configuration.
- **Scalable Design**:
  - Handles large datasets with millions of operations in minimal time.

---

## File Descriptions
- **`avl.h` and `avl.cpp`**:
  - Implements the AVL tree with support for:
    - Word insertion.
    - Range query computation using subtree sizes.
- **`main.cpp`**:
  - Handles input and output file processing.
  - Integrates the AVL tree for performing insertions and queries.
- **`wordrange`**:
  - The compiled executable created by the Makefile.
  - Processes operations as specified in the input file and writes results to the output file.
- **`Makefile`**:
  - Automates the compilation process to generate the executable.

---

## How It Works
1. **Input Format**:
   - Each line of the input file specifies an operation:
     - **Insert**: `i <WORD>` adds `<WORD>` to the AVL tree (if not already present).
     - **Range Query**: `r <LOW> <HIGH>` outputs the count of words in the range `[LOW, HIGH]`.
   - Example:
     ```
     i apple
     i banana
     r a z
     ```

2. **Output Format**:
   - For each range query (`r <LOW> <HIGH>`), outputs a single integer representing the count of words in the range.

---

## Instructions
1. **Compile the Program**:
   - Navigate to the project directory and run:
     ```bash
     make
     ```

2. **Run the Program**:
   - Use the following command:
     ```bash
     ./wordrange <input_file> <output_file>
     ```
   - Ensure both `<input_file>` and `<output_file>` are `.txt` files.

3. **Example Usage**:
   - Input (`input.txt`):
     ```
     i apple
     i banana
     r a c
     ```
   - Command:
     ```bash
     ./wordrange input.txt output.txt
     ```
   - Output (`output.txt`):
     ```
     2
     ```

---

## Performance
The program processes:
- **1 million insertions**.
- **2 million range queries**.
All operations complete in under one minute, demonstrating the efficiency of AVL tree-based implementations.

---


## Additional Notes
- The `wordrange` executable:
  - Implements both insertion and range query operations.
  - Uses lexicographical comparisons for string operations.
- Subtree sizes enable logarithmic complexity for range queries, ensuring scalability.

---


