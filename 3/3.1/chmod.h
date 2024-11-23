#include <sys/stat.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

enum class { 
	CLASS_OWNER, 
	CLASS_GROUP, 
	CLASS_OTHER 
};

enum permission { 
	PERMISSION_READ, 
	PERMISSION_WRITE, 
	PERMISSION_EXECUTE 
};

mode_t perm(enum class c, enum permission p);
bool mode_contains(mode_t mode, enum class c, enum permission p);
mode_t mode_add(mode_t mode, enum class c, enum permission p);
mode_t mode_rm(mode_t mode, enum class c, enum permission p) ;
mode_t add_mask(mode_t mode, mode_t mask);
mode_t rm_mask(mode_t mode, mode_t mask);
// buf must have at least 10 bytes
void strmode(const mode_t mode, char * buf);
mode_t modestr(char* str);
mode_t get_file_mode(const char* path);

// u+x
mode_t my_chmod_str(mode_t mode, char* chg_str);
mode_t my_chmod_num(mode_t mode, mode_t changes);

/*
000 0
001 1
010 2
011 3
100 4
101 5
110 6
111 7
*/
