#include <stdio.h>
#include <arpa/inet.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define BITS_I32 32
#define BITS_IN_SEG 8
#define SEG_COUNT 4
#define MIN_NUM_FOR_IP 16777216
#define MAX_NUM_FOR_IP 4294967295

typedef struct packet_t {
    unsigned int ip_src;
    unsigned int ip_dst;
} packet_t;

unsigned int convert_mask_to_u_int(const char* mask);
/*
generate network mask
Example:
input: 24
output: 4294967040 (11111111111111111111111100000000)
*/
unsigned int gen_net_mask(const unsigned int count);
unsigned int gen_rand_ip();
unsigned int ipcmp(unsigned int ip_src, unsigned int ip_dst, unsigned int mask); // Compare part of ip with subnet address between two ip adresses; return 0 - if equal;
void printb(const unsigned char c, FILE* outstream); // Print bits of u_char variable
void printbi(const unsigned int k, FILE* outstream); // Print bits of i_int variable
void printip(const unsigned int k, FILE* outstream); // Print variable in IPv4-format
void printmask(const unsigned int mask, FILE* outstream); // Print variable in IP-mask-format
