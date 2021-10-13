#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate length without dirrect accessing with []
int my_strlen(const char *str)
{
	const char* start = str;
	int length = 0;

	while(*start)
	{
		length++;
		start++;
	}

	return length;
}

void mirror(char *s)
{
	int length = my_strlen(s);
	
	for(int i = 0; i < length / 2; ++i)
	{
		char tmp = *(s + i);
		*(s + i) = *(s + length - 1 - i);
		*(s + length-1-i) = tmp;
	}
}

int main()
{
	// Initial string
	char* input = calloc(20, sizeof(char));
	strcpy(input, "AnaAreMere");
	printf("String: %s\n", input);

	// Reversed string
	mirror(input);
	printf("Reversed string: %s\n", input);
	free(input);

	return 0;
}

