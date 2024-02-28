#include <stdio.h>

int main(void)
{
	int var_a = 0xAACC7733;
	char *ptr = NULL;

	ptr = (char *)&var_a;

	printf("Variable a (HEX) = %X\n", var_a);

	printf("First byte of variable a (HEX) = %X\n",(int)(*ptr)&0xFF);
	printf("Second byte of variable a (HEX) = %X\n",(int)(*(ptr+1))&0xFF);
	printf("Third byte of variable a (HEX) = %X\n",(int)(*(ptr+2))&0xFF);
	printf("Fourth byte of variable a (HEX) = %X\n",(int)(*(ptr+3))&0xFF);

	printf("\nChanging the third byte of varibale a (CC-->>73)\n");
	*(ptr+2) = (char)((int)(0x73));
	printf("Variable a (HEX) = %X\n", var_a);


	return 0;
}
