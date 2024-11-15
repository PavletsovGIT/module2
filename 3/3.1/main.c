#include "chmod.h"

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

int main() {
	
	unsigned int perms = 511;
	
	char* users = "go", rights = "rw";
	
	printrights(del_permissions(users, rights, perms), stdout);
	
	/*
	// 1)
	char result;
	
	char* mod1 = "u+rw";
	
	char* mod2 = "rx";
	
	char* mod3 = "ug+wx";
	
	char mod4 = 0b000000011;
	char* mod4_0 = "o-x";
	
	result = str_to_binary(mod1);
	printstr(result, stdout);
	printd(result, stdout);
	printb(result, stdout);
	
	result = str_to_binary(mod2);
	printstr(result, stdout);
	printd(result, stdout);
	printb(result, stdout);
	
	result = str_to_binary(mod3);
	printstr(result, stdout);
	printd(result, stdout);
	printb(result, stdout);
	
	result = str_to_binary(mod4_0);
	printstr(result, stdout);
	printd(result, stdout);
	printb(result, stdout);
	*/
	
	/*
	struct roots_t roots[] = {
		{'r', 0b100100100}, 
		{'w', 0b010010010}, 
		{'x', 0b001001001}, 
		{'u', 0b100100100}, 
		{'g', 0b100100100}, 
		{'o', 0b100100100}, 
		{'a', 0b111111111}, 
		{'0', 0b000000000} 
	};
	
	char X = 755;
	
	printf("%X\n", X);
	printf("%X\n", X << 5);
	
	printb(1, stdout);
	*/
	
	return 0;	
}


