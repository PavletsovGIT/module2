#include "calc.h"

double Summ(int n, ...) 
{
	double result = 0;
	
	va_list factor;
	va_start(factor, n);
	
	for (int i = 0; i < n; i++)
	{
		result += va_arg(factor, double);
	}
	
	va_end(factor);
	
	return result;
}

double Defference(int n, ...)
{
	double result = 0;
	
	va_list factor;
	va_start(factor, n);
	
	result = va_arg(factor, double);
	
	for (int i = 0; i < n - 1; i++)
	{
		result -= va_arg(factor, double);
	}
	
	va_end(factor);
	
	return result;
}

double Multiply(int n, ...) {
    double result = 1;
    
    va_list factor;
    va_start(factor, n);
    
    for (int i = 0; i < n; i++) {
        result *= va_arg(factor, double);
    }
    
    va_end(factor);
    
    return result;
}

double Divide(int n, ...) {
    double result = 0;
    
    va_list factor;
    va_start(factor, n);
    
    result = va_arg(factor, double);
    
    for (int i = 0; i < n - 1; i++) {
        double next = va_arg(factor, double);
        
        if (next == 0) {
            printf("Ошибка: деление на ноль!\n");
            return -1;
        }
        
        result /= next;
    }
    
    va_end(factor);
    
    return result;
}
