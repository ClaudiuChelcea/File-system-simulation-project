#include <stdio.h>

void main(void)
{
	int v[] = {4, 1, 2, -17, 15, 22, 6, 2};
	int n = 8;
	int max;

	/* TODO: Implement finding the maximum value in the vector */
	max = v[0];
	int i = 1;

loop_again: 
	if(max < v[i]) {
		max = v[i];
	}

	i++;
	if(i < n)
		goto loop_again;

	printf("Max element: %d!\n", max);
}
