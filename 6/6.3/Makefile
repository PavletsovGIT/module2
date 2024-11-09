CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean

all: libs/libsumm.so libs/libdiff.so libs/libmult.so libs/libdiv.so app

app:
	$(CC) $(CFLAGS) -o app main.o -L libs/*.so -lmyLibrary -lm

main.o: src/main.c
	$(CC) $(CFLAGS) -c main.o -o main.c
	
libs/libsumm.so: summ.o
	$(CC) $(CFLAGS) -shared -o libs/libsumm.so summ.o -lm

libs/libdiff.so: diff.o
	$(CC) $(CFLAGS) -shared -o libs/libdiff.so diff.o -lm

libs/libmult.so: mult.o
	$(CC) $(CFLAGS) -shared -o libs/libmult.so mult.o -lm

libs/libdiv.so: div.o
	$(CC) $(CFLAGS) -shared -o libs/libdiv.so div.o -lm

summ.o: src/summ.c
	$(CC) $(CFLAGS) -fPIC -c summ.o -o src/summ.c

diff.o: src/diff.c
	$(CC) $(CFLAGS) -fPIC -c diff.o -o src/diff.c

mult.o: src/mult.c
	$(CC) $(CFLAGS) -fPIC -c mult.o -o src/mult.c

div.o: src/div.c
	$(CC) $(CFLAGS) -fPIC -c div.o -o src/div.c

clean:
	rm -f ./*.o ./libs/*.so app 
