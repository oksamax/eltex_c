#include <stdio.h>

int main(void)
{
	int var_a = 0xAACC7733;

	printf("Variable a (HEX) = %X\n", var_a);

	printf("First byte of variable a (HEX) = %X\n",(var_a & 0xFF));
	printf("Second byte of variable a (HEX) = %X\n",((var_a >> 8) & 0xFF));
	printf("Third byte of variable a (HEX) = %X\n",((var_a >> 16) & 0xFF));
	printf("Fourth byte of variable a (HEX) = %X\n",((var_a >> 24) & 0xFF));

	printf("\nChanging the third byte of varibale a (CC-->>73)\n");
	printf("Variable a (HEX) = %X\n", (var_a & 0xFF00FFFF) | 0x730000);

	return 0;
}
