#include <stdarg.h>

double Summ(int n, ...) 
{
	double result = 0;
	
	va_list factor;
	va_start(factor, n);
	
	for (int i = 0; i < n; i++)
	{
		result += va_arg(factor, double) * 2;
	}
	
	va_end(factor);
	
	return result;
}

