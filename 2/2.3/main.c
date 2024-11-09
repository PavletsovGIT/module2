#include <stdio.h>

double Summ(double arg1, double arg2) { return arg1 + arg2; }
double Defference(double arg1, double arg2) { return arg1 - arg2; }
double Multipile(double arg1, double arg2) { return arg1 * arg2; }
double Division(double arg1, double arg2) { return (arg2 == 0) ? -1 : arg1 / arg2; }

double ErrorChoice(double arg1, double arg2) { return -1; }

double (*Select(int choice))(double, double) {
	switch(choice) {
		case 1: return Summ;
		case 2: return Defference;
		case 3: return Multipile;
		case 4: return Division;
		default: return ErrorChoice;
	}
}

int main() {
	double (*action)(double, double);
	
	int choice;
	double arg1 = 0, arg2 = 0, result = 0;
	
	while(1) {
		printf("To select action, type action number:\n");
		printf("1. Summ\n");
		printf("2. Defference\n");
		printf("3. Multipile\n");
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
