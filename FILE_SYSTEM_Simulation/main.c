#include "execute_commands.h"
#include "receive_commands.h"
#include "support.h"

int main(void)
{
	// The command received
	char *command = NULL;
	command = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
	DIE(!command, "Couldn't allocate memory for receiving commands!");

	// Current directory
	Dir *directory = default_directory();
	strcat(directory->name, "home");

	do {
        // Get the command
		scanf("%s", command);

        // For every command, assign it a number with the recognize command function
        // and execute the right command by giving that number to a switch loop
        // in the scan_and_execute_command function
	} while (scan_and_execute_command(recognize_command(command), &directory));

	// Release memory
	free(command);

	return 0;
}
