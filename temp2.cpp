#include <stdio.h>

int array();

int main()
{
    array();
    return 0;
}

int array()
{
    long myarr[2][4] = {0l,1l,2l,3l,4l,5l,6l,7l};
    printf("%ld", myarr[1][2]);
    printf("%ld%ld", *(myarr[1]+3), 3[myarr[1]]);
    printf("%ld%ld%ld", *(*(myarr+1)+2), *(1[myarr] + 2), 3[1[myarr]]);
    
    return 0;
}