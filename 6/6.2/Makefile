# Имя исполняемого файла
TARGET = app

# Имя динамической библиотеки
LIBNAME = libcontacts.so

# Флаги компилятора
CFLAGS = -Wall -g -fpic

# Линковщик
LD = gcc

# Флаг для линкования динамических библиотек
LDFLAGS = -shared

# Исходные файлы для библиотеки
SRCS_LIB = contacts.c

# Объектные файлы для библиотеки
OBJS_LIB = $(SRCS_LIB:.c=.o)

# Исходный файл для исполняемого файла
SRC_MAIN = main.c

# Объектный файл для исполняемого файла
OBJ_MAIN = $(SRC_MAIN:.c=.o)

.PHONY: all clean genlib

all: $(TARGET)

genlib: $(LIBNAME)

$(TARGET): $(OBJ_MAIN) $(LIBNAME)
	$(LD) $(CFLAGS) $^ -o $@

$(LIBNAME): $(OBJS_LIB)
	$(LD) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS_LIB) $(OBJ_MAIN) $(LIBNAME)
