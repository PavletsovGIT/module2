TARGET = app

CC = gcc

CFLAGS = -Wall

SRC_MAIN = main.c

OBJ_MAIN = main.o

SRC_LIB = bin_tree.c

OBJ_LIB = bin_tree.o

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ_MAIN) $(OBJ_LIB)
	$(CC) $(OBJ_MAIN) $(OBJ_LIB) -o $(TARGET)

$(OBJ_MAIN): $(SRC_MAIN)
	$(CC) $(CFLAGS) -c $(SRC_MAIN)

$(OBJ_LIB): $(SRC_LIB)
	$(CC) $(CFLAGS) -c $(SRC_LIB)
