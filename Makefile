# Compiler and flags
CC = g++
CFLAGS = -std=c++17 -Wall -g

# Target executables
AVL_EXEC = wordrange
NAIVE_EXEC = naive_wordrange

# Source files
AVL_SRCS = main.cpp avl.cpp
NAIVE_SRCS = main_naive.cpp naive.cpp

# Object files
AVL_OBJS = $(AVL_SRCS:.cpp=.o)
NAIVE_OBJS = $(NAIVE_SRCS:.cpp=.o)

# Default target (build both executables)
all: $(AVL_EXEC) $(NAIVE_EXEC)

# Build AVL Tree executable
$(AVL_EXEC): $(AVL_OBJS)
	$(CC) $(CFLAGS) -o $@ $(AVL_OBJS)

# Build Naive BST executable
$(NAIVE_EXEC): $(NAIVE_OBJS)
	$(CC) $(CFLAGS) -o $@ $(NAIVE_OBJS)

# Compile source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	del /f *.o $(AVL_EXEC).exe $(NAIVE_EXEC).exe

