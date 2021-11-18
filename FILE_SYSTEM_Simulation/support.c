#include "support.h"

// Create a default directory
Dir* default_directory() {

	// Allocate memory
	Dir* directory = NULL;
    directory = calloc(1, sizeof(*directory));
    DIE(!directory, "Couldn't allocate space for directory");

	// Default fields
    directory->head_children_dirs = NULL;
    directory->head_children_files = NULL;

	// Name
	directory->name = NULL;
	directory->name = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
	DIE(!directory->name, "Couldn't allocate default directory name!");

	// Other default fields
    directory->next = NULL;
    directory->parent = NULL;

	return directory;
}

// Create a default directory
File* default_file (Dir* parent, char* file_name) {
	// Create file
	File* fptr = NULL;
	fptr = calloc(1, sizeof(*fptr));
	DIE(!fptr, "Couldn't create file!");

	// Allocate fields
	fptr->next = NULL;
	
	// Name
	fptr->name = NULL;
	fptr->name = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
	strcat(fptr->name, file_name);

	return fptr;
}

void release_directory(Dir* directory_name) {
	// Directory structure
	free(directory_name->name);

	// Free all files in root directory
	File* first_file_in_directory = directory_name->head_children_files;
	File* tmp = NULL;
	while(first_file_in_directory) {
		tmp = first_file_in_directory;
		first_file_in_directory = first_file_in_directory->next;
		free(tmp->name);
		free(tmp);
		tmp = NULL;
	}
	free(directory_name);
	directory_name = NULL;
}

static void release_directory_structure(Dir* root) {
	
	if(root) {
		if(root->head_children_dirs)
			release_directory_structure(root->head_children_dirs);
		release_directory_structure(root->next);
		release_directory(root);
	}
}

// Release the memory
void release_memory (Dir* root_directory) {

	release_directory_structure(root_directory);
}