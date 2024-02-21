#include <stdio.h>

int main(void)
{
	float a = 1;
	for(;;) {
		a += 100 ;
		printf("a = %f\n", a);
	}

	return 0;
}
