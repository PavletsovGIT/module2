CC = gcc
CFLAGS = -Wall
OBJ = main.o contacts.o
TARGET = a.out

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

main.o: main.c contacts.h
	$(CC) $(CFLAGS) -c main.c

contacts.o: contacts.c contacts.h
	$(CC) $(CFLAGS) -c contacts.c

clean:
	rm -rf *.o *.out



