#include <stdio.h>
#include "calc.h"

int main()
{
    printf("Summ of 1, 2, 3, 4, 5 = %lf\n", Summ(5, 1.0, 2.0, 3.0, 4.0, 5.0));
    printf("Difference of 1.535, 2, 3, 4, 5 = %lf\n", Defference(5, 1.535, 2.0, 3.0, 4.0, 5.0));
    printf("Multiply of 1.535, 2, 3, 4, 5 = %lf\n", Multiply(5, 1.535, 2.0, 3.0, 4.0, 5.0));
    printf("Division of 10.535, 5, 3, 4, 5 = %lf\n", Divide(5, 10.535, 5.0, 3.0, 4.0, 5.0)); 
    printf("Division of 10.535, 5, 3, 4, 5 = %lf\n", Divide(2, 5.0, -5.0)); 

    return 0;
}
