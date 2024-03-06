#include <stdio.h>

struct no_pack {
	char a;
	int b;
};

struct pack {
	char a;
	int b;
} __attribute__((packed));



int main(void)
{
	struct no_pack *ptr_no_pack = NULL;
	struct pack *ptr_pack = NULL;
	char a[10] = {'A',0,0,0,0,'B',0,0,0,0};

	ptr_no_pack = (struct no_pack *)a;
	ptr_pack = (struct pack *) a;

	printf("No packed a1 = %c  b1 = %d  a2 = %c  b2 = %d\n", ptr_no_pack -> a, ptr_no_pack -> b, (ptr_no_pack+1) -> a, (ptr_no_pack+1) -> b);
	printf("Packed a1 = %c  b1 = %d  a2 = %c  b2 = %d\n", ptr_pack -> a, ptr_pack -> b, (ptr_pack+1) -> a, (ptr_pack+1) -> b);

	return 0;
}
