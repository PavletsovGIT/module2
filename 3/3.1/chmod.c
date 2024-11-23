#include "chmod.h"

const mode_t EMPTY_MODE = 0;

mode_t perm(enum class c, enum permission p) { 
	return 1 << ((3-p) + (2-c)*3); 
}

bool mode_contains(mode_t mode, enum class c, enum permission p) { 
	return mode & perm(c, p); 
}

mode_t mode_add(mode_t mode, enum class c, enum permission p) { 
	return mode | perm(c, p); 
}

mode_t mode_rm(mode_t mode, enum class c, enum permission p) { 
	return mode & ~perm(c, p); 
}

mode_t add_mask(mode_t mode, mode_t mask) {
	return mode | mask;
}

mode_t rm_mask(mode_t mode, mode_t mask) {
	return mode & ~mask;
}

// buf must have at least 10 bytes
void strmode(const mode_t mode, char * buf) {
  const char chars[] = "rwxrwxrwx";
  for (size_t i = 0; i < 9; i++) {
    buf[i] = (mode & (1 << (8-i))) ? chars[i] : '-';
  }
  buf[9] = '\0';
}

mode_t modestr(char* str) {
	mode_t mode = 0;
	for (size_t i = 0; i < 9; i++) {
		mode |= (str[i] == '-') ? 0 : (1 << (8-i));
	}
	return mode;
}

mode_t get_file_mode(const char* path) {
	struct stat buf;
	int err = stat(path, &buf);
	if (err != 0) return err;
	return buf.st_mode;
}

mode_t my_chmod_str(mode_t mode, char* chg_str) {
	int i;
	mode_t chg_mode = 0, usrs = 0, perm = 0;
	
	mode_t(*action)(mode_t mode, mode_t mask);
	
	// changes_str to chanes_mode
	for (i = 0; i < strlen(chg_str); i++) {
		switch (chg_str[i]) {
			case 'u':
				usrs |= 0700;
				break;
			case 'g':
				usrs |= 0070;
				break;
			case 'o':
				usrs |= 0007;
				break;
			case 'r':
				perm |= 0444;
				break;
			case 'w':
				perm |= 0222;
				break;
			case 'x':
				perm |= 0111;
				break;
			case 'a':
				usrs |= 0777;
				break;
			case '+':
				action = add_mask;
				break;
			case '-':
				action = rm_mask;
				break;
			default:
				break;
		}
	}
	
	chg_mode = usrs & perm;
	mode = action(mode, chg_mode);
	return  mode;
}

mode_t my_chmod_num(mode_t mode, mode_t changes) {
	mode = changes;
	return mode;
}
