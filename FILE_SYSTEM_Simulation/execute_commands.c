#include "execute_commands.h"
#define MAX_PATHS 50

// Create a file
void touch(Dir *parent, char *name)
{
	// Check name
	if (strcmp(parent->name, name) == 0) {
		printf("%s", "File already exists\n");
		return;
	}

	// Create a file
	File *new_file = default_file(name);

	// Fix linking
	new_file->parent = parent;
	if (!parent->head_children_files) {
		parent->head_children_files = new_file;
	} else {
		File *beginning = parent->head_children_files;

		// Test with first file
		if (strcmp(beginning->name, name) == 0) {
			printf("%s", "File already exists\n");
			free(new_file->name);
			free(new_file);
			return;
		}
		while (beginning->next) { // Test with other files
			if (strcmp(beginning->name, name) == 0) {
				printf("%s", "File already exists\n");
				free(new_file->name);
				free(new_file);
				return;
			}
			beginning = beginning->next;
		}
		beginning->next = new_file;
	}
}

// Create a directory
void mkdir(Dir *parent, char *name)
{
	// Check if the parent`s name is the same with the folder`s
	if (strcmp(parent->name, name) == 0) {
		printf("Directory already exists\n");
		return;
	}

	// Check all subfolders name
	Dir* start = parent->head_children_dirs;
	while(start) {
		if(strcmp(start->name, name) == 0) {
			printf("Directory already exists\n");
			return;
		}
		start = start->next;
	}

	Dir *directory = default_directory();

	// Set name
	strcat(directory->name, name);

	// Linking
	directory->parent = parent;
	if (!parent->head_children_dirs) {
		parent->head_children_dirs = directory;
	} else {
		// Add the directory to the end
		Dir *start = parent->head_children_dirs;
		while (start->next) {
			start = start->next;
		}
		start->next = directory;
	}
}

// List the items in the current directory
void ls(Dir *parent)
{
	// List all directories
	Dir *start = parent->head_children_dirs;
	while (start) {
		printf("%s\n", start->name);
		start = start->next;
	}

	// List files
	File *start2 = parent->head_children_files;
	while (start2) {
		printf("%s\n", start2->name);
		start2 = start2->next;
	}
}

// Remove a file
void rm(Dir *parent, char *name)
{
	File *start = parent->head_children_files;

	// Check if we have files in the directory
	if (!parent->head_children_files) {
		printf("Could not find the file\n");
		return;
	}

	// If we want to remove the first file
	if (strcmp(parent->head_children_files->name, name) == 0) {
		parent->head_children_files = parent->head_children_files->next;
		free(start->name);
		free(start);
		start = NULL;
		return;
	} else {
		while (start->next) { // Other files, but not the first
			if (strcmp(start->next->name, name) == 0) {
				File *tmp = start->next;
				start->next = start->next->next;
				free(tmp->name);
				free(tmp);
				tmp = NULL;
				return;
			}
			start = start->next;
		}
	}
	printf("Could not find the file\n");
}

// Remove a directory
void rmdir(Dir *parent, char *name)
{
	// Check if we have any directories
	Dir *subfolder = parent->head_children_dirs;
	if (!subfolder) {
		printf("Could not find the dir\n");
		return;
	}

	// Check first subdirectory
	if (strcmp(subfolder->name, name) == 0) {
		parent->head_children_dirs = parent->head_children_dirs->next;
		release_directory(subfolder);
		return;
	} else { // Check all others subdirectories
		while (subfolder->next) {
			if (strcmp(subfolder->next->name, name) == 0) {
				Dir *current = subfolder->next;
				subfolder->next = subfolder->next->next;
				release_directory(current);
				return;
			}
			subfolder = subfolder->next;
		}
	}
	printf("Could not find the dir\n");
}

// Change directory
void cd(Dir **target, char *name)
{
	// Check if we can go to parent, and, if true, do it
	if (strcmp(name, "..") == 0) {
		if (!(*target)->parent) {
			return; // change to parent
		} else {
			(*target) = (*target)->parent;
			return;
		}
	} else { // Find if the subdirectory exists and, if true, go into it
		Dir *start = (*target)->head_children_dirs;
		while (start) {
			if (strcmp(start->name, name) == 0) {
				(*target) = start;
				return;
			}
			start = start->next;
		}
	}
	printf("No directories found!\n");
}

// Show current path
char *pwd(Dir *target)
{
	// String of strings to hold the name of each folder to the root
	char **string_array = NULL;
	string_array = calloc(MAX_PATHS, sizeof(char *));
	DIE(!string_array, "Couldn't allocate memory for paths!");

	// Get names;
	int count = 0;
	Dir *copy = target;
	while (copy) {
		string_array[count] = NULL;
		string_array[count] = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
		DIE(!string_array[count], "Couldn't allocate path!");
		strcat(string_array[count++], copy->name);
		copy = copy->parent;
	}

	// Create a string with all the names
	char *full_path = NULL;
	full_path = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
	DIE(!full_path, "Couldn't allocate full path!");

	strcat(full_path, "/");
	for (int i = count - 1; i >= 0; --i) {
		strcat(full_path, string_array[i]);
		if (i != 0)
			strcat(full_path, "/");
	}

	// Delete array
	for (int i = 0; i < count; ++i) {
		free(string_array[i]);
	}
	free(string_array);
	
	// Return the fully created path
	return full_path;
}

// Stop the program and release the memory
void stop(Dir *target)
{
	release_memory(target);
}

// Print all the directories and files in a tree structure
void tree(Dir *target, int level)
{
	if (target) {
		// Current directory name
		for (int i = 0; i < level - 1; ++i)
			printf("    ");
		printf("%s\n", target->name);

		// Other directories
		if (target->head_children_dirs)
			tree(target->head_children_dirs, level + 1);

		// Files
		File *start = target->head_children_files;
		while (start) {
			for (int i = 0; i < 4 * level; ++i)
				printf(" ");
			printf("%s\n", start->name);
			start = start->next;
		}

		// Move to the next directory recursively
		tree(target->next, level);
	}
}

// Change the name of a file / directory
void mv(Dir *parent, char *oldname, char *newname)
{
	// Search if name exists in dirs
	Dir *startDir = parent->head_children_dirs;
	while (startDir) {
		if (strcmp(startDir->name, newname) == 0) {
			printf("File/Director already exists\n");
			return;
		}
		startDir = startDir->next;
	}

	// Search if name exists in files
	File *startFile = parent->head_children_files;
	while (startFile) {
		if (strcmp(startFile->name, newname) == 0) {
			printf("File/Director already exists\n");
			return;
		}
		startFile = startFile->next;
	}

	// If the new name doesn't exist, we can do the mv operation
	// So we search for the oldname
	startDir = parent->head_children_dirs;

	if (startDir && strcmp(startDir->name, oldname) == 0) { // First dir
		// Change name
		free(startDir->name);
		startDir->name = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
		strcat(startDir->name, newname);

		// Move to the end
		Dir *start = startDir;
		if (parent->head_children_dirs->next) {
			parent->head_children_dirs = parent->head_children_dirs->next;
			Dir *loop = parent->head_children_dirs;
			while (loop && loop->next) {
				loop = loop->next;
			}
			loop->next = start;
			loop->next->next = NULL;
		}
		return;

	} else { // Not the first directory
		while (startDir && startDir->next) {

			if (strcmp(startDir->next->name, oldname) == 0) {

				// Change name
				free(startDir->next->name);
				startDir->next->name =
					calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
				strcat(startDir->next->name, newname);

				// Move to the end
				Dir *keep = startDir->next;
				keep->next = NULL;
				startDir->next = startDir->next->next;
				while (startDir && startDir->next)
					startDir = startDir->next;
				startDir->next = keep;
				return;
			}
			startDir = startDir->next;
		}
	}

	// The same thing with files
	// If no directory matched the name so it can't be moved
	// check the files
	startFile = parent->head_children_files;

	if (startFile && strcmp(startFile->name, oldname) == 0) { // First file
		// Change name
		free(startFile->name);
		startFile->name = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
		strcat(startFile->name, newname);

		// Move to the end
		File *start = startFile;
		if (parent->head_children_files->next) {
			parent->head_children_files = parent->head_children_files->next;
			File *loop = parent->head_children_files;
			while (loop && loop->next) {
				loop = loop->next;
			}
			loop->next = start;
			loop->next->next = NULL;
		}
		return;
	} else { // Any other file, but not the first
		while (startFile && startFile->next) {
			if (strcmp(startFile->next->name, oldname) == 0) {
				// Change name
				free(startFile->next->name);
				startFile->next->name =
					calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
				strcat(startFile->next->name, newname);

				// Move to the end
				File *keep = startFile->next;
				startFile->next = startFile->next->next;
				while (startFile && startFile->next)
					startFile = startFile->next;
				startFile->next = keep;
				keep->next = NULL;
				return;
			}
			startFile = startFile->next;
		}
	}

	// If the oldname file/dir doesn't exist
	printf("File/Director not found\n");
}
