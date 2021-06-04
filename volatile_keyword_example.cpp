
// When compiled with optimisations ON and without volatile, value will remain 10
#include <iostream>

int main(void)
{
    const volatile int local = 10;
    int *ptr = (int*) &local;
  
    printf("Initial value of local : %d \n", local);
  
    *ptr = 100;
  
    printf("Modified value of local: %d \n", local);
  
    return 0;
}