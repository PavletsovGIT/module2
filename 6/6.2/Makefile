TARGET = app

CC = gcc 

CFLAGS = -Wall

LIBNAME = libcontacts

LIB = libcontacts.so

LIBFLAG = -lcontacts

SRC_LIB = contacts.c

OBJ_LIB = contacts.o

SRC_MAIN = main.c

OBJ_MAIN = main.o

.PHONY: all clean

all: $(TARGET)

$(OBJ_LIB): $(SRC_LIB)
	$(CC) $(CFLAGS) -fPIC -c $(SRC_LIB)

$(OBJ_MAIN): $(SRC_MAIN)
	$(CC) $(CFLAGS) -c $(SRC_MAIN)
	
$(LIB): $(OBJ_LIB)
	$(CC) -shared $(OBJ_LIB) -o $(LIB)
	
$(TARGET): $(OBJ_MAIN) $(LIB) $(LIBFLAG)
	$(CC) $(OBJ_MAIN) -L. $(LIBFLAG) -o $(TARGET)

clean:
	rm *.o *.so

# Если программа пишет что не может найти библиотеку:
# 1. Проверяем есть ли переменная LD_LIBRARY_PATH:
# 1.1 $echo LD_LIBRARY_PATH
# Если в выводе ничего, значит переменная есть (используем пункт 2), если нет, то пункт 3
# 2.
# $ LD_LIBRARY_PATH=/home/pavletsov21/eltex/module2/6/6.2:${LD_LIBRARY_PATH}
# $ export LD_LIBRARY_PATH
# 3. 
# $ LD_LIBRARY_PATH=/home/pavletsov21/eltex/module2/6/6.2
# $ export LD_LIBRARY_PATH
# 4. Проверяем нашла ли сама система библиотеку:
# $ ldd app
# Неправильный вывод:
#	linux-vdso.so.1 (0x00007ffc8a95d000)
#  libcontacts.so => not found
#	 libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007ff7a1044000)
#	 /lib64/ld-linux-x86-64.so.2 (0x00007ff7a1240000)
# Правильный вывод:
#	 linux-vdso.so.1 (0x00007ffd8dfcf000)
# 	 libcontacts.so => /home/pavletsov21/eltex/module2/6/6.2/libcontacts.so (0x00007f69e355a000)
#	 libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f69e3365000)
#	 /lib64/ld-linux-x86-64.so.2 (0x00007f69e3566000)
