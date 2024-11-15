#include "chmod.h"

static bin_mod mods[MOD_COUNT] = {
	{'u', 448}, 
	{'g', 56}, 
	{'o', 7}, 
	{'r', 292}, 
	{'w', 146}, 
	{'o', 73}, 
	{'a', 511}
};

unsigned int intlen(unsigned int n) {
	unsigned int count = 0;
	while (n != 0) {
		count++;
		n /= 10;
	}
	return count;
}

unsigned int int_to_persmissions(unsigned int n) { // n = 755
	unsigned int i, perms = 0, m; // rights = 0b000000000
	
	// for others
	m = n % 10;
	perms |= (m << O); 
	n /= 10;
	
	// for groups
	m = n % 10;
	perms |= (m << G);
	n /= 10;
	
	// for user
	m = n % 10;
	perms |= (m << U);
	n /= 10;
	
	return perms;
}

unsigned int add_permissions(char* users, char* rights, unsigned int perms) {
	int i, j;
	unsigned int my_perms = 0;
	// for users
	for (i = 0; i < strlen(users); i++) { // get from users
		for (j = 0; j < MOD_COUNT; j++) {
			if (users[i] == mods[j].ch) {
				my_perms |= mods[j].n;
			}
		}
	}
	
	// for rights
	for (i = 0; i < strlen(rights); i++) { // get from users
		for (j = 0; j < MOD_COUNT; j++) {
			if (rights[i] == mods[j].ch) {
				my_perms &= mods[j].n;
			}
		}
	}
	
	return perms | my_perms;
}

unsigned int set_permissions(char* users, char* rights, unsigned int perms) {
	int i, j;
	perms = 0;
	// for users
	for (i = 0; i < strlen(users); i++) { // get from users
		for (j = 0; j < MOD_COUNT; j++) {
			if (users[i] == mods[j].ch) {
				perms |= mods[j].n;
			}
		}
	}
	
	// for rights
	for (i = 0; i < strlen(rights); i++) { // get from users
		for (j = 0; j < MOD_COUNT; j++) {
			if (rights[i] == mods[j].ch) {
				perms &= mods[j].n;
			}
		}
	}
	
	return perms;
}

unsigned int del_permissions(char* users, char* rights, unsigned int perms) {
	int i, j;
	
	for (i = 0; i < strlen(users); i++) {
		for (j = 0; j < MOD_COUNT; j++) {
			if (users[i] == mods[j].ch) {
				perms &= ~mods[j].n;
			}
		}
	}
	
	
	for (i = 0; i < strlen(rights); i++) {
		for (j = 0; j < MOD_COUNT; j++) {
			if (rights[i] == mods[j].ch) {
				perms |= ~mods[j].n;
			}
		}
	}
	
	return perms;
}

/*
	users means u/g/o/a
	rights means r/w/x
	perms means rw-r-x--x
*/
unsigned int str_to_rights(char* str, unsigned int perms) {
	int i = 0;
	char* users, rights;
	unsigned int (*action)(char* users, char* rights, unsigned int perms) = NULL;
	users = strtok(str, "+-="); // Разделяем строку по знаку
	rights = strtok(NULL, "+-=");
	
	for (i = 0; i < strlen(str); i++) {
		if (str[i] == '+') {
			action = add_permissions;
			break;
		}
		if (str[i] == '-') {
			action = del_permissions;
			break;
		}
		if (str[i] == '=') {
			action = set_permissions;
			break;
		}
	}
	if (action == NULL) return 0;
	
	return action(users, rights, perms);
}

void printrights(const unsigned int k, FILE* outstream) {
	int a, i = 0;
	
	for ( ; i < RB_SIZE; i++) {
		a = k >> i;
		
		(a & 1) ? fprintf(outstream, "1") : fprintf(outstream, "0");
	}
}

void printbi(const unsigned int k, FILE* outstream) {
	int a, i = BITS_I32;
	
	for ( ; i >= 0; i--) {
		a = k >> i;
		
		(a & 1) ? fprintf(outstream, "1") : fprintf(outstream, "0");
	}
}
