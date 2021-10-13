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

// Display the elements on the i position who are
// equal to the i + 2^i position using only
// bit operations when possible
void equality_check(const char *str)
{
	// Display the length
	int str_length = my_strlen(str);
	printf("length = %d\n\n",str_length);

	// Check
	for(int i = 0; i < str_length; ++i)
	{
		int pos = i + (1 << i);
		if(pos >= str_length)
			pos = pos % str_length;

		if(*(str + i) == *(str + pos))
			printf("Address of %c is %p\n",*(str + i), str + i);
	}
}


int main(void)
{
	equality_check("ababababacccbacbacbacbacbabe");

	return 0;
}

