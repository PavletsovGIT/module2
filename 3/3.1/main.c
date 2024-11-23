/*
3.1 (2 балла). Написать программу для расчета маски прав доступа к файлу.
1)Пользователь может ввести права доступа в буквенном или цифровом
обозначении, ему должно быть показано соответствующее битовое
представление.
2)Пользователь может ввести имя файла, и ему отобразится буквенное,
цифровое и битовое представление прав доступа. Использовать функцию stat
для получения информации о файле. Сравнить результат с выводом,
например, ls -l.
3)Пользователь может изменить права доступа, определенные в первом или
втором пункте, введя команды модификации атрибутов (подобно команде
chmod). При этом отображается буквенное, цифровое и битовое
представление прав доступа. Изменение прав доступа не нужно применять к
файлу.
*/

#include "chmod.h"

static const char path[] = "main.c";

// print binary mode
void print_bm(mode_t mode) {
	int a, i;
	
	for (i = 0; i < 9; i++) {
		a = mode >> i;
		
		(a & 1) ? printf("1") : printf("0");
	}
}

void test_modestr() {
	char* chars = "rw-r--r--";
	mode_t perm = modestr(chars);
	
	printf("Test modestr %s: %3o\n", chars, perm & 0777);
}

void test_printMode() {
	char buff[9];
	mode_t perm = get_file_mode(path);
	strmode(perm, buff);
	printf("Test printMode %s : %3o\n", buff, perm&0777); 
}

void test_firstPoint() {
	char buff[9];
	
 	mode_t f_mode = get_file_mode(path);
 	strmode(f_mode, buff);
 	printf("File: %s\n", path);
 	printf("Words: %s\n", buff);
	printf("Nums: %3o\n", f_mode & 0777);
	printf("Bits: "); print_bm(f_mode); printf("\n");
}

void test_myChmodStr() {
	char changes[] = "ug+wx";
	char buff[9];
	
	mode_t mode = get_file_mode(path);
	mode = my_chmod_str(mode, changes);
	
	strmode(mode, buff);
	
	printf("After my_chmod_str:\n");
	printf("Words: %s\n", buff);
	printf("Nums: %3o\n", mode & 0777);
	printf("Bits: "); print_bm(mode); printf("\n");
}

void test_myChmodNum() {
	mode_t changes = 0330;
	char buff[9];
	
	mode_t mode = get_file_mode(path);
	mode = my_chmod_num(mode, changes);
	
	strmode(mode, buff);
	
	printf("After my_chmod_num:\n");
	printf("Words: %s\n", buff);
	printf("Nums: %3o\n", mode & 0777);
	printf("Bits: "); print_bm(mode); printf("\n");
}

int main(void) {
	test_modestr();
	test_printMode();
	test_firstPoint() ;
	test_myChmodStr();
	test_myChmodNum();
	
	return 0;
}
