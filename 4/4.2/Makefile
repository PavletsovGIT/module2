TARGET = app

SRC = queue2
MAIN = main

CC = gcc

CFLAGS = -Wall

.PHONY: all clean

$(TARGET): $(MAIN).o $(SRC).o
	$(CC) $(CFLAGS) $(MAIN).o $(SRC).c -o $(TARGET)

$(MAIN).o: $(MAIN).c
	$(CC) $(CFLAGS) -c $(MAIN).c

$(SRC).o: $(SRC).c
	$(CC) $(CFLAGS) -c $(SRC).c

clean:
	rm *.o
