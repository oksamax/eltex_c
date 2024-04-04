#include <alloca.h>
#include <stdio.h>

int main(void)
{
    int *ptr1 = NULL, *ptr2 = NULL;

    ptr1 = alloca(8);
    ptr2 = alloca(8);

    *ptr1 = 1;
    *(ptr1 +1) = 2;
    *ptr2 = 3;
    *(ptr2 +1) = 4;

    printf("%d %d %d %d\n", *ptr1, *(ptr1 +1), *ptr2, *(ptr2 +1));

    return 0;
}