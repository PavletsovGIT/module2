#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef double (*operation_func)(double, ...);
typedef struct {
	const char* name;
	operation_func func;
} operation;

static operation_func Summ, Difference, Multiply, Division;

double ErrorChoice(double arg1, double arg2);

double (*Select(int choice))(double, double);

// handle wrapper
operation_func GetFuncPtr(const char* path_lib, const char* func_name);

int main() {

	Summ = GetFuncPtr("./libs/libsumm.so", "Summ");
	Difference = GetFuncPtr("./libs/libdiff.so", "Diff");
	Multiply = GetFuncPtr("./libs/libmult.so", "Multilpy");
	Division = GetFuncPtr("./libs/libdiv.so", "Division");
	
	double (*action)(double, double);
	
	int choice;
	double arg1 = 0, arg2 = 0, result = 0;
	
	while(1) {
		printf("To select action, type action number:\n");
		printf("1. Summ\n");
		printf("2. Difference\n");
		printf("3. Multiply\n");
		printf("4. Division\n\n");
		
		printf("Action num = ");
		scanf("%d", &choice);
		
		action = Select(choice);
		
		printf("Arg1 = ");
		scanf("%lf", &arg1);
		printf("Arg2 = ");
		scanf("%lf", &arg2);
		
		result = action(arg1, arg2);
		
		printf("Result = %lf\n\n", result);
	}
	
	return 0;
}

double ErrorChoice(double arg1, double arg2) { return -1; }

double (*Select(int choice))(double, double) {
	switch(choice) {
		case 1: return Summ;
		case 2: return Difference;
		case 3: return Multiply;
		case 4: return Division;
		default: return ErrorChoice;
	}
}

// handle wrapper
operation_func GetFuncPtr(const char* path_lib, const char* func_name) {
	void* handle;
	operation_func op;
	
	handle = dlopen(path_lib, RTLD_LAZY);
	
	if (!handle) {
		frptinf(stderr, "Can't load .so: %s\n", dlerror());
		exit(1);
	}
	
	op = (operation_func) dlsym(handle, func_name);
	
	if (!op) {
		fprintf(stderr, "Can't get func: %s\n", dlerror());
		dlclose(handle);
		exit(1);
	}
	
	return op;
}
