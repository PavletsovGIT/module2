#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef double (*operation_func)(int, ...);
typedef struct {
	const char* name;
	operation_func func;
} operation;

static operation_func Summ, Difference, Multiply, Division;

double ErrorChoice();

double (*Select(int choice))(int, ...);

// handle wrapper
operation_func GetFuncPtr(const char* path_lib, const char* func_name);

int main() {
	
	double (*action)(int, ...);
	double result = 0;
	
	Summ = GetFuncPtr("./libs/libsumm.so", "Summ");
	Difference = GetFuncPtr("./libs/libdiff.so", "Difference");
	Multiply = GetFuncPtr("./libs/libmult.so", "Multiply");
	Division = GetFuncPtr("./libs/libdiv.so", "Devide");
	
	action = Select(1);
	
	result = action(5, 1.0, 2.0, 3.0, 4.0, 5.0);
	printf("Action: Summ | Result = %lf\n", result);
	
	action = Select(2);
	
	result = action(5, 1.0, 2.0, 3.0, 4.0, 5.0);
	printf("Action: Difference | Result = %lf\n", result);
	
	action = Select(3);
	
	result = action(4, 1.0, 2.0, 3.0, 4.0);
	printf("Action: Multiply | Result = %lf\n", result);
	
	action = Select(4);
	result = action(3, 3.0, 2.0, 1.0);
	printf("Action: Devide | Result = %lf\n", result);
	
	/*
	double (*action)(double, double);
	
	int choice, n = 0;
	double arg1 = 0, arg2 = 0, result = 0;
	
	while(1) {
		printf("To select action, type action number:\n");
		printf("1. Summ\n");
		printf("2. Difference\n");
		printf("3. Multiply\n");
		printf("4. Division\n\n");
		
		printf("Action num = ");
		scanf("%d", &choice);
		
		printf("Count of numbers = ");
		scanf("%d", &n);
		
		action = Select(choice);
		
		printf("Arg1 = ");
		scanf("%lf", &arg1);
		printf("Arg2 = ");
		scanf("%lf", &arg2);
		
		result = action(n, arg1, arg2);
		
		printf("Result = %lf\n\n", result);
	}
	*/
	
	return 0;
}

double ErrorChoice() { return -1; }

double (*Select(int choice))(int,  ...) {
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
		fprintf(stderr, "Can't load .so: %s\n", dlerror());
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
