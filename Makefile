# Compiler and flags
CC = g++
CFLAGS = -std=c++17 -Wall -g

# Target executable
TARGET = wordrange

# Source files
SRCS = main.cpp avl.cpp
wordrange: main.o avl.o
	g++ -o wordrange main.o avl.o

main.o: main.cpp
	g++ -c main.cpp

avltree.o: avl.cpp avl.h
	g++ -c avl.cpp

clean:
	del /f main.o avl.o wordrange.exe

