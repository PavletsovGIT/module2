CC = gcc
CFLAGS = -Wall -Wextra -std=c11
OBJ = main.o calc.o
TARGET = calc

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

main.o: main.c calc.h
	$(CC) $(CFLAGS) -c main.c

calc.o: calc.c calc.h
	$(CC) $(CFLAGS) -c calc.c

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean

