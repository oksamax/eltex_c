#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    long int *ptr1 = NULL;
    double *ptr2 = NULL;
    
    ptr1 = sbrk(16);

    if(ptr1 < 0) {
        printf("MEMORY ALLOCATION ERROR!!!");
        exit(EXIT_FAILURE);
    }

    ptr2 = sbrk(16);

    if(ptr2 < 0) {
        printf("MEMORY ALLOCATION ERROR!!!");
        exit(EXIT_FAILURE);
    }

    *ptr1 = 8;
    *(ptr1 + 1) = 16;

    *ptr2 = 11.1;
    *(ptr2 + 1) = 12.2;

    printf("%ld %ld %.2f %.2f\n", *ptr1, *(ptr1 + 1), *ptr2, *(ptr2 + 1));

    sbrk(-32);

    return 0;
}