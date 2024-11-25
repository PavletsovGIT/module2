#include "ip2.h"

unsigned int convert_mask_to_u_int(const char* mask) {
	unsigned int base = 0;
	int i = 0;
	char* str_num = strtok(mask, ".");
	
	while (str_num != NULL) {
		base += (atoi(str_num) * pow(2, 24 - (BITS_IN_SEG * i)));
		i++;
		str_num = strtok(NULL, ".");
	}
	
	return base;
}

unsigned int gen_net_mask(const unsigned int count) {
	unsigned int mask = 0, i = 0, one = 1;
	
	for (i = BITS_I32 - 1; i >= BITS_I32 - count; i--) {
		mask |= (one << i);
	}
	
	return mask;
}

unsigned int gen_rand_ip() {
	static int seed = 0;
	srand(time(NULL) + ++seed);
	
	return rand() % (MIN_NUM_FOR_IP + MAX_NUM_FOR_IP) + MIN_NUM_FOR_IP;
}

unsigned int ipcmp(unsigned int ip_src, unsigned int ip_dst, unsigned int mask) {
	return (ip_src >> (BITS_I32 - mask)) ^ (ip_dst >> (BITS_I32 - mask));
}

void printb(const unsigned char c, FILE* outstream) {
	int a, i;
	
	for (i = BITS_IN_SEG - 1; i >= 0; i--) {
		a = c >> i;
		
		(a & 1) ? fprintf(outstream, "1") : fprintf(outstream, "0");
	}
}

void printbi(const unsigned int k, FILE* outstream) {
	int a, i = BITS_I32 - 1;
	
	for ( ; i >= 0; i--) {
		a = k >> i;
		
		(a & 1) ? fprintf(outstream, "1") : fprintf(outstream, "0");
	}
}

void printip(const unsigned int k, FILE* outstream) {
    int i, j = BITS_IN_SEG;
    unsigned char X;
    unsigned char result[SEG_COUNT];
    for (i = SEG_COUNT - 1; i >= 0; i--) {
        X = k >> j * i;
        
        result[i] = X;
    }
    
    for (i = SEG_COUNT - 1; i >= 0; i--) {
        fprintf(outstream, "%d.", result[i]);
    } fprintf(outstream, "%d", result[SEG_COUNT - 1]);
}

void printmask(const unsigned int mask, FILE* outstream) {
	unsigned int f_num = 0, s_num = 0, th_num = 0, fth_num = 0;
	
	f_num |= (mask << 24) >> 24;
	
	s_num |= (mask << 16) >> 24;
	
	th_num |= (mask << 8) >> 24;
	
	fth_num |= mask >> 24;
	
	fprintf(outstream, "%u.", fth_num); fprintf(outstream, "%u.", th_num);fprintf(outstream, "%u.", s_num); fprintf(outstream, "%u", f_num); 
}
