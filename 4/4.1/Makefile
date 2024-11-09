CC = gcc
CFLAGS = -Wall -Wextra -std=c11
OBJ = main.o contacts.o
TARGET = contacts_app

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

main.o: main.c contacts.h
	$(CC) $(CFLAGS) -c main.c

contacts.o: contacts.c contacts.h
	$(CC) $(CFLAGS) -c contacts.c

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean

