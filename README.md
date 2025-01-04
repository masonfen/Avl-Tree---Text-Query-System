# Avl-Tree---Text-Query-System

This program implements an AVL tree for managing a collection of words,
it supports inserting words into the tree and efficiently querying the number of words within a specified range.

Compile the program using make (from the Makefile)

Run the program with an input and output txt file:

./wordrange <input file> <output file>

"i <word>": inserts the word into the AVL tree
"r <low> <high>": outputs the count of wrods in the range "low, high"

avltree.h and avltree.cpp are the implementations of the AVL tree (the logic behind everything)
main.cpp: handles the file input/output and provides the main logic for the usage of these files
