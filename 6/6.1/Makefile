#Приложение
TARGET = app

# Компилятор C
CC = gcc

# Имя статической библиотеки
LIBNAME = libcontacts.a
LIBFLAG = -lcontacts

# Список исходных файлов для библиотеки
SRC_LIB = contacts.c

# Объектные файлы для библиотеки
OBJS_LIB = $(SRC_LIB:.c=.o)	

# Список исходного файла для исполняемого файла
SRC_MAIN = main.c

# Объектный файл для исполняемого файла
OBJ_MAIN = $(SRC_MAIN:.c=.o)

.PHONY: all clean

all: $(TARGET)
	
$(OBJS_LIB): $(SRCS_LIB)
	$(CC) -c -fPIC $(SRC_LIB)

$(LIBNAME): $(OBJS_LIB)
	ar -rc $(LIBNAME) $(OBJS_LIB)

$(OBJ_MAIN): $(SRC_MAIN)
	$(CC)  $(SRC_MAIN) -c $(OBJ_MAIN)

$(TARGET): $(OBJ_MAIN) $(LIBNAME)
	$(CC) $(OBJ_MAIN) -L. $(LIBFLAG) -o $(TARGET)

clean:
	rm -f $(TARGET) $(OBJS_LIB) $(OBJ_MAIN) $(LIBNAME)

# gcc contacts.c -c contacts.o
# ar rcs libcontacts.a contacts.o
# gcc main.c -L. -lfs -o app
