TARGET = a.out

CC = gcc

CFLAGS = -Wall

.PHONY: all clean

all: $(TARGET)

$(TARGET): main.o chmod.o
	$(CC) main.o chmod.o -o $(TARGET)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

chmod.o: chmod.c
	$(CC) $(CFLAGS) -c chmod.c
	
clean:
	rm -rf *.o a.out
