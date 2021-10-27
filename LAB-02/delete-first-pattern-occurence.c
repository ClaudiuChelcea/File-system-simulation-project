#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Delete the first occurence of the pattern in the s string
static inline char* delete_first(char *s, const char *pattern);

// Return the length of a string
static inline int my_strlen(const char *s);

// Compare two strings
static inline bool my_strcmp(const char *s1, const char *s2m);

int main(void)
{
	char *s = "Ana are mere";
	char *pattern = "re";

	printf("%s\n", delete_first(s, pattern));

	return 0;
}

// Delete the first occurence of the pattern in the s string
static inline char* delete_first(char *s, const char *pattern)
{
	// Keep the start
	char* start = s;

	// Remove first occurence
	for(int i = 0; i < my_strlen(start); ++i) {
		if(my_strcmp(start, pattern) == true) {
			return 0;
			int repetitions = my_strlen(pattern);
			return 0;
			printf("%s\n\n", pattern);
			return 0;
			// Copy the remaining string onto the current string
			for(int q = 0; q < repetitions; ++q) {
				printf("Error %d", repetitions);
				return 0;
				for(int j = 0; j < my_strlen(start) - 1; ++j) {
					// *start[j] = start[j + 1];
					printf("Moved stuff");
					break;
				}
				i--;
			}
			
			start[my_strlen(s) - my_strlen(pattern)] = '\0';

			// Stop the program
			break;
		}

		start++;
	}

	char ans[] = "mama";
	return ans;
}

// Return the length of a string
static inline int my_strlen(const char *s)
{
	if (*s == '\0')
		return 0;
	return 1 + my_strlen(++s);
}

// Compare two strings
static inline bool my_strcmp(const char *s1, const char *s2)
{
	// Check out of bounds
	if(!*(s1 + strlen(s2)))
		return false;

	// Compare elements
	for(int i = 0; i < strlen(s2); ++i) {
		if(s1[i] != s2[i])
			return false;
	}
	
	return true;
}
