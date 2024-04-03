#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int *ptr = NULL, i = 0;

    ptr = malloc(sizeof(int)*4);

    if(0 == ptr) {
        printf("MEMORY ALLOCATION ERROR!!!\n");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < 4; i++) {
        *(ptr + i) = i+1;
        printf("%d  ",*(ptr + i));
    }
    printf("\n");
    free(ptr);



    ptr = calloc(2, sizeof(int));

    if (0 == ptr) {
        printf("MEMORY ALLOCATION ERROR!!!\n");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < 2; i++) {
        *(ptr + i) = i+1;
        printf("%d  ",*(ptr + i));
    }
    printf("\n");



    ptr = realloc(ptr, 8*sizeof(int));

    if (0 == ptr) {
        printf("MEMORY ALLOCATION ERROR!!!\n");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < 8; i++) {
        *(ptr + i) = i+1;
        printf("%d  ",*(ptr + i));
    }
    printf("\n");

    free(ptr);

    return 0;
}