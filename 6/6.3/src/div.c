#include <stdarg.h>

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