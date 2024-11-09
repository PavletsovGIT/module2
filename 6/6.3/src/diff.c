#include <stdarg.h>

double Difference(int n, ...)
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

