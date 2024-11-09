TARGET = app

CC = gcc

CFLAGS = -Wall

SRC_MAIN = src/main.c

SRC_SUMM = src/summ.c

SRC_DIFF = src/diff.c

SRC_MULT = src/mult.c

SRC_DIV = src/div.c

OBJ_MAIN = main.o

OBJ_SUMM = summ.o

OBJ_DIFF = diff.o

OBJ_MULT = mult.o

OBJ_DIV = div.o

LIBSUMM = ./libs/libsumm.so

LIBDIFF = ./libs/libdiff.so

LIBMULT = ./libs/libmult.so

LIBDIV = ./libs/libdiv.so

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ_MAIN) $(LIBSUMM) $(LIBDIFF) $(LIBMULT) $(LIBDIV)
	$(CC) $(OBJ_MAIN) -L./libs/ -lsumm -ldiff -lmult -ldiv -o $(TARGET)

$(OBJ_MAIN): $(SRC_MAIN)
	$(CC) $(CFLAGS) -c $(SRC_MAIN)

$(OBJ_SUMM): $(SRC_SUMM)
	$(CC) $(CFLAGS) -fPIC -c $(SRC_SUMM)
	
$(OBJ_DIFF): $(SRC_DIFF)
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIFF)

$(OBJ_MULT): $(SRC_MULT)
	$(CC) $(CFLAGS) -fPIC -c $(SRC_MULT)

$(OBJ_DIV): $(SRC_DIV)
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIV)

$(LIBSUMM): $(OBJ_SUMM)
	$(CC) -shared $(OBJ_SUMM) -o $(LIBSUMM)

$(LIBDIFF): $(OBJ_DIFF)
	$(CC) -shared $(OBJ_DIFF) -o $(LIBDIFF) 

$(LIBMULT): $(OBJ_MULT)
	$(CC) -shared $(OBJ_MULT) -o $(LIBMULT) 

$(LIBDIV): $(OBJ_DIV)
	$(CC) -shared $(OBJ_DIV) -o $(LIBDIV) 
