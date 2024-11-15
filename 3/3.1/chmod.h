#ifndef CHMOD_H_
#define CHMOD_H_

#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BITS_I32 32
#define MAX_DIGIT_RIGHTS 3
#define RB_SIZE 9 // Number of bits in rights
#define MOD_COUNT 7

#define U 0
#define G 3
#define O 6
#define R 0
#define W 1
#define X 2

typedef struct bin_mod {
	unsigned char ch;
	unsigned int n;
} bin_mod;



// Return length of num
unsigned int intlen(unsigned int n);
// Convert integer to rights in binary format
unsigned int int_to_persmissions(unsigned int n);
unsigned int add_permissions(char* users, char* rights, unsigned int perms);
unsigned int set_permissions(char* users, char* rights, unsigned int perms);
unsigned int del_permissions(char* users, char* rights, unsigned int perms);
// Convert string to rights in binary format
unsigned int str_to_rights(char* str, unsigned int perms);
// Print unsigned int like rigths
void printrights(const unsigned int k, FILE* outstream);
// Print unsigned int in binary format
void printbi(const unsigned int k, FILE* outstream); // Print bits of u_int variable

#endif // CHMOD_H_
