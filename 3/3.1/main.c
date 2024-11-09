#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CH_M_SIZE 9
#define I_M_SIZE 3

void PrintIntArr(int* arr, size_t size);
char ConvertStrToBinary(const char* src);
char ConvertCharToBinary(char c);
void printb(char c);

int main() {
	char result = 0b000000000;

	// Пользователь вводит права доступа в буквенном значении, выводится соответствующее битовое значение
	char user_c_mod[CH_M_SIZE] = "ug+r";
	result = ConvertStrToBinary(user_c_mod);
	printb(result);
	
	return 0;	
}

char ConvertStrToBinary(const char* src) {
	char result = 0b000000000;	
	
	for (int i = 0; i < CH_M_SIZE; i++) {
		if (src[i] == 'r' || src[i] == 'w' || src[i] == 'x') {
			result &= ConvertCharToBinary(src[i]);
		} else {
			result |= ConvertCharToBinary(src[i]);
		}
	}
	
	return result;
}

char ConvertCharToBinary(char c) {
	switch (c) {
		case 'u':
			return 0b111000000;
		case 'g':
			return 0b000111000;
		case 'o':
			return 0b000000111;
		case 'a':
			return 0b111111111;
		case 'r':
			return 0b100100100;
		case 'w':
			return 0b010010010;
		case 'x':
			return 0b001001001;
		default:
			return 0b000000000;
	}
}

void printb(char c) {
	int a, i = 0;
	
	for ( ; i < CH_M_SIZE; i++) {
		a = c >> i;
		
		(a & 1) ? printf("1") : printf("0");
	}
	printf("\n");
}
