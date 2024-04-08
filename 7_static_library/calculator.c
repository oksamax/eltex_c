#include "calc.h"
#include <stdio.h>

int main(void)
{
    int var_a = 0, var_b = 0, item = 0;

    do {
        printf("***Calculator***\n     Menu:\n   1.Additional\n   2.Subtraction\n   3.Multiplication\n   4.Division\n   5.Exit\n\n");
        printf("Enter the item:");
        scanf("%d", &item);
        if(1 == item){
            printf("Additional (a + b)\nEnter variable a:");
            scanf("%d", &var_a);
            printf("Enter variable b:");
            scanf("%d", &var_b);
            printf("Result (a + b) = %d\n", add(var_a, var_b));
        }
        else if (2 == item) {
            printf("Subtraction (a - b)\nEnter variable a:");
            scanf("%d", &var_a);
            printf("Enter variable b:");
            scanf("%d", &var_b);
            printf("Result (a - b) = %d\n", sub(var_a, var_b));
        }
        else if (3 == item) {
            printf("Multiplication (a * b)\nEnter variable a:");
            scanf("%d", &var_a);
            printf("Enter variable b:");
            scanf("%d", &var_b);
            printf("Result (a * b) = %d\n", mul(var_a, var_b));
        }
        else if (4 == item) {
            printf("Division (a \\ b)\nEnter variable a:");
            scanf("%d", &var_a);
            printf("Enter variable b:");
            scanf("%d", &var_b);
            printf("Result (a \\ b) = %d\n", div(var_a, var_b));
        }
        else if (item != 5) printf("This item is not in the menu!!!");
        printf("\n\n");
    } while(item != 5);

    return 0;
}