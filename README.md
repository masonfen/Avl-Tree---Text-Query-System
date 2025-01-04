# Avl-Tree---Text-Query-System

## Overview
This program implements an **AVL tree** for managing a collection of words. It supports:
- **Insertions**: Add unique words into the tree.
- **Range Queries**: Efficiently query the number of words within a specified lexicographical range.
1. **Optimized AVL Tree**:
   - Supports efficient insertions and range queries using a self-balancing AVL tree.
2. **Naive BST**:
   - Provides a baseline for comparison by implementing a simple, unbalanced binary search tree (BST) with less efficient operations.

The naive implementation highlights the performance gains achieved by the AVL tree in ter

---

## Features
### Optimized AVL Tree
- **Logarithmic Complexity**:
  - AVL Tree ensures balanced height for efficient insertions and lookups.
- **Augmented Range Queries**:
  - Subtree size augmentation enables quick range query computation.

### Naive BST
- **Unbalanced Growth**:
  - Demonstrates inefficient performance with skewed or large datasets.
- **Linear Complexity**:
  - Operations may degrade to \(O(n)\), providing a worst-case baseline for comparison.

---

## File Descriptions
- **`avl.h` and `avl.cpp`**:
  - Implements the optimized AVL tree with:
    - Word insertion.
    - Fast range queries using subtree sizes.
- **`naive.h` and `naive.cpp`**:
  - Implements a simple, unbalanced BST for:
    - Basic word insertion.
    - Inefficient range queries requiring full-tree traversal.
- **`main.cpp`**:
  - Uses the AVL tree for performing insertions and range queries.
- **`main_naive.cpp`**:
  - Uses the naive BST to perform the same operations for performance comparison.
- **`Makefile`**:
  - Automates the compilation of both versions into separate executables:
    - `wordrange` for the AVL tree.
    - `naive_wordrange` for the naive BST.
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




## Additional Notes
- The `wordrange` executable:
  - Implements both insertion and range query operations.
  - Uses lexicographical comparisons for string operations.
- Subtree sizes enable logarithmic complexity for range queries, ensuring scalability.

## For benchmark testing
Run both implementations with the same dataset to observe differences in:
- Runtime performance.
- Memory usage.

Example commands:
```bash
./wordrange input.txt output_avl.txt
./naive_wordrange input.txt output_naive.tx



