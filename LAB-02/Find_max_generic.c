#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// FInd max
void *find_max(void *arr, int n, int element_size, 
			   int (*compare)(const void *, const void *))
{
	void *max_elem = arr;

	for(int i = 0; i < n; ++i)
	{
		if(compare(max_elem, (int*) arr + i) == 0)
		{
			*((int*)max_elem) = *((int*)arr + i);
		}
	}

	return max_elem;
}

// Compare two int elements
int compare(const void *a, const void *b)
{
	if(*((int*) a) >= *((int*) b))
		return 1;

	return 0;
}

// Find max element
int main(void)
{
	int n;
	scanf("%d", &n);

	int *arr = malloc(n * sizeof(*arr));

	for (int i = 0 ; i < n; ++i)
		scanf("%d", &arr[i]);      

	printf("Max is: %d!\n", *((int*) find_max(arr, n, sizeof(*arr), compare))); 

	free(arr);
	return 0;
}
