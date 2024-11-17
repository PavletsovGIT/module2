#include "chmod.h"

static bin_mod mods[MOD_COUNT] = {
	{'u', 448}, 
	{'g', 56}, 
	{'o', 7}, 
	{'r', 292}, 
	{'w', 146}, 
	{'x', 73}, 
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

unsigned int int_to_permissions(unsigned int n) { // n = 755
	unsigned int perms = 0, m; // rights = 0b000000000
	
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

unsigned int create_str_mask(char* str) {
    int i, j, res = 0;
    
    for (i = 0; i < strlen(str); i++) {
		for (j = 0; j < MOD_COUNT; j++) {
			if (str[i] == mods[j].ch) {
				res |= mods[j].n;
			}
		}
	}
	
	return res;
}

unsigned int add_permissions(char* users, char* rights, unsigned int perms) {
	unsigned int usr_mask, rgh_mask, buff;
	
	usr_mask = create_str_mask(users);
	rgh_mask = create_str_mask(rights);
	
	buff = usr_mask & rgh_mask;
	
	return perms | buff;
}

unsigned int set_permissions_s(char* str) {
    unsigned int res = 0;
    int i;
    
    if (strlen(str) != RB_SIZE) {return 0;}
    
    for (i = 0; i < RB_SIZE; i++) {
        if (str[i] != '-') {
            res |= 1 << i;
        }
    }
    
    return res;
}

unsigned int set_permissions_u(unsigned int n) {
    return int_to_permissions(n);
}

unsigned int del_permissions(char* users, char* rights, unsigned int perms) {
	unsigned int usr_mask, rgh_mask, buff;
	
	usr_mask = create_str_mask(users);
	rgh_mask = create_str_mask(rights);
	
	buff = usr_mask & rgh_mask;
	
	return perms ^ buff;
}

/*
	users means u/g/o/a
	rights means r/w/x
	perms means rw-r-x--x
*/

// return permissions in format rw-r--r--
// buf must have at least 10 bytes
void strmode(mode_t mode, char* buf) {
  const char chars[] = "rwxrwxrwx";
  for (size_t i = 0; i < 9; i++) {
    buf[i] = (mode & (1 << (8-i))) ? chars[i] : '-';
  }
  buf[9] = '\0';
}

void printrights(const unsigned int k, FILE* outstream) {
	int a, i;
	
	for (i = RB_SIZE - 1; i >= 0; i--) {
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
