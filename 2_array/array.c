#include <stdio.h>

#define N 10

int main(void)
{
	int square_matrix[N][N] = {0}, inverse_matrix[N] = {0}, traingular_matrix[N][N] = {0} , snail_matrix[N][N] = {0};
	int i = 0, j = 0, max = 0, min = 0, counter = 0, n = 0, count = 0;

	printf("\n1. Square matrix. Please, enter size of matrix n (from 1 to 10):");
	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			counter++;
			square_matrix[i][j] = counter;
			printf("%2d ",square_matrix[i][j]);
		}
		printf("\n");
	}


	printf("\n\n2. Inverse matrix. Please, enter size of matrix n (from 1 to 10):");
	scanf("%d", &n);
	counter = 0;

	printf("Matrix: ");
	for(i = 0; i < n; i++) {
		counter++;
		inverse_matrix[i] = counter;
		printf("%2d ",inverse_matrix[i]);
	}
	printf("\nInverse matrix: ");
	for(i = 0; i < n; i++) {
		printf("%2d ",inverse_matrix[n-i-1]);
	}


	printf("\n\n3. Traingular matrix. Please, enter size of matrix n (from 1 to 10):");
	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if ((i + j) <= (n -2)) {
				traingular_matrix[i][j] = 0;
				printf("%2d ", traingular_matrix[i][j]);
			} else {
				traingular_matrix[i][j] = 1;
				printf("%2d ", traingular_matrix[i][j]);
			}
		}
		printf("\n");
	}

	printf("\n\n4. Snail matrix. Please, enter size of matrix n (from 1 to 10):");
	scanf("%d", &n);

	counter = 1;
	count = n/2;
	max = n;
	min = 0;
	i = j = min;

	while(count > 0) {

		i = min;
		j = min;

		while(j < max) {
			snail_matrix[i][j] = counter;
			counter++;
			j++;
		}

		j--;
		i++;

		while(i < max) {
			snail_matrix[i][j] = counter;
			counter++;
			i++;
		}

		j--;
		i--;

		while(j > (min-1)) {
			snail_matrix[i][j] = counter;
			counter++;
			j--;
		}

		j++;
		i--;

		while (i > min) {
			snail_matrix[i][j] = counter;
			counter++;
			i--;
		}

		count--;
		min++;
		max--;
	}

	if(n % 2) snail_matrix[n/2][n/2] = counter; 


	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("%3d ",snail_matrix[i][j]);
		}
		printf("\n");
	}




	return 0;
}
