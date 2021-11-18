#include "receive_commands.h"
#define LEVEL 1

// Scan input based on the received number from a command and execute it
bool scan_and_execute_command(int command_number, Dir **current_directory)
{
	// Varibles
	char *file_name = NULL, *file_name_2 = NULL, *dir_name = NULL,
         *output = NULL;
	

	switch (command_number) {

	case 1: // TOUCH
		// Get file name
		file_name = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
		DIE(!file_name, "Couldn't read file name in the touch function!");
		scanf("%s", file_name);

		touch(*current_directory, file_name);
		break;

	case 2: // MKDIR
		// Get directory name
		dir_name = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
		DIE(!dir_name, "Couldn't read directory name in the mkdir function!");
		scanf("%s", dir_name);

		mkdir(*current_directory, dir_name);
		break;

	case 3: // LS
		ls(*current_directory);
		break;

	case 4: // RM
		// Get file name
		file_name = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
		DIE(!file_name, "Couldn't read file name in the touch function!");
		scanf("%s", file_name);

		rm(*current_directory, file_name);
		break;

	case 5: // RMDIR
		// Get directory name
		dir_name = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
		DIE(!dir_name, "Couldn't read directory name in the mkdir function!");
		scanf("%s", dir_name);
        
		rmdir(*current_directory, dir_name);
		break;

	case 6: // CD
		// Get directory name
		dir_name = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
		DIE(!dir_name, "Couldn't read directory name in the mkdir function!");
		scanf("%s", dir_name);

		cd(current_directory, dir_name);
		break;

	case 7: // TREE
        if((*current_directory)->head_children_dirs) {
            cd(current_directory, (*current_directory)->head_children_dirs->name);
		    tree(*current_directory, LEVEL);
		    cd(current_directory, "..");

            // Show files
            File* start = (*current_directory)->head_children_files;
            while(start) {
                printf("%s\n", start->name);
                start = start->next;
            }
        } else {
            ls(*current_directory);
        }
		break;

	case 8: // PWD
		output = pwd(*current_directory);

		printf("%s\n", output);
		free(output);
		output = NULL;
		break;

	case 9: // STOP
		while ((*current_directory)->parent)
			(*current_directory) = (*current_directory)->parent;
		stop(*current_directory);

		return false;

	case 10: // MV
		// Get oldname name
		file_name = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
		DIE(!file_name, "Couldn't read file name in the touch function!");
		scanf("%s", file_name);

		// Get newname name
		file_name_2 = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
		DIE(!file_name_2, "Couldn't read file name in the touch function!");
		scanf("%s", file_name_2);

		mv(*current_directory, file_name, file_name_2);

        // Release extra memory
		free(file_name);
		free(file_name_2);
		return true;

	case -1: // Unrecognized command
		return true;

	default: // Unrecognized command
		return true;
	}

    // Release pointers if allocated above
	if (file_name) 
		free(file_name);
	if (file_name_2) 
		free(file_name);
	if (dir_name) 
		free(dir_name);
	if (output) 
		free(output);
	
	return true;
}

// Recognize the command and return a number for it
int recognize_command(char *command)
{
	if (strcmp(command, "touch") == 0)
		return 1;
	else if (strcmp(command, "mkdir") == 0)
		return 2;
	else if (strcmp(command, "ls") == 0)
		return 3;
	else if (strcmp(command, "rm") == 0)
		return 4;
	else if (strcmp(command, "rmdir") == 0)
		return 5;
	else if (strcmp(command, "cd") == 0)
		return 6;
	else if (strcmp(command, "tree") == 0)
		return 7;
	else if (strcmp(command, "pwd") == 0)
		return 8;
	else if (strcmp(command, "stop") == 0)
		return 9;
	else if (strcmp(command, "mv") == 0)
		return 10;
	else
		return -1;
}
