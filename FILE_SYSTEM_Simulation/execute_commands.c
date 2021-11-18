#include "execute_commands.h"
#define MAX_PATHS 50

void touch (Dir* parent, char* name) {

	// Check name
	if(strcmp(parent->name, name) == 0) {
		printf("%s","File already exists\n");
		return;
	}
	
	// Create a file
	File* new_file = default_file(parent, name);

	// Fix linking
	new_file->parent = parent;
	if(!parent->head_children_files) {
		parent->head_children_files = new_file;
	} else {
		File* beginning = parent->head_children_files;
		// Test with first file
		if(strcmp(beginning->name, name) == 0) {
			printf("%s","File already exists\n");
			free(new_file->name);
			free(new_file);
			return;
		}
		while(beginning->next) {
			if(strcmp(beginning->name, name) == 0) {
				printf("%s","File already exists\n");
				free(new_file->name);
				free(new_file);
				return;
			}
			beginning = beginning->next;
		}
		beginning->next = new_file;
	}
}

void mkdir (Dir* parent, char* name) {
	if(strcmp(parent->name, name) == 0) {
		printf("Directory already exists\n");
		return;
	}

	Dir* directory = default_directory();

	// Set name
	strcat(directory->name, name);

	// Linking
	directory->parent = parent;

	if(!parent->head_children_dirs) {
		parent->head_children_dirs = directory;
	} else {
		// Add the directory to the end
		Dir* start = parent->head_children_dirs;
		while(start->next) {
			start = start->next;
		}
		start->next = directory;
	}
}

void ls (Dir* parent) {
	Dir* start = parent->head_children_dirs;

	while(start) {
		printf("%s\n",start->name);
		start = start->next;
	}

	File* start2 = parent->head_children_files;
	while(start2) {
		printf("%s\n",start2->name);
		start2 = start2->next;
	}
}

void rm (Dir* parent, char* name) {

	File* start = parent->head_children_files;

	// First element
	if(!parent->head_children_files) {
		printf("Could not find the file\n");
		return;
	}

	if(strcmp(parent->head_children_files->name, name) == 0) {
		parent->head_children_files = parent->head_children_files->next;
		free(start->name);
		free(start);
		start = NULL;
		return;
	} else {
		while(start->next) {
			if(strcmp(start->next->name, name) == 0) {
				File* tmp = start->next;
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

void rmdir (Dir* parent, char* name) {
	
	Dir* subfolder = parent->head_children_dirs;
	if(!subfolder) {
		printf("Could not find the dir\n");
		return;
	}

	if(strcmp(subfolder->name, name) == 0) {
		parent->head_children_dirs = parent->head_children_dirs->next;
		release_directory(subfolder);
		return;
	} else {
		while(subfolder->next) {
			if(strcmp(subfolder->next->name, name) == 0) {
				Dir* current = subfolder->next;
				subfolder->next = subfolder->next->next;
				release_directory(current);
				return;
			}
			subfolder = subfolder->next;
		}
	}
	
	printf("Could not find the dir\n");
}

void cd (Dir** target, char *name) {

	if(strcmp(name, "..") == 0) { 
		if(!(*target)->parent) {
			return;// change to parent
		} else {
			(*target) = (*target)->parent; // de ce nu merge
			return;
		}
	} else {
		Dir* start = (*target)->head_children_dirs;
		while(start) {
			if(strcmp(start->name, name) == 0) {
				(*target) = start; // de ce nu merge
				return;
			}
			start = start->next;
		}
 	}

	printf("No directories found!\n");

}

char *pwd (Dir* target) {
	// String of strings to hold the name of each folder to the root
	char** string_array = NULL;
	string_array = calloc(MAX_PATHS, sizeof(char*));
	DIE(!string_array, "Couldn't allocate memory for paths!");

	// Get names;
	int count = 0;
	Dir* copy = target;
	while(copy) {
		string_array[count] = NULL;
		string_array[count] = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
		DIE(!string_array[count], "Couldn't allocate path!");
		strcat(string_array[count++], copy->name);
		copy = copy->parent;
	}

	// d1 home
	char* full_path = NULL;
	full_path = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
	DIE(!full_path, "Couldn't allocate full path!");
	strcat(full_path,"/");
	for(int i = count - 1; i >= 0; --i) {
		strcat(full_path, string_array[i]);
		if(i != 0)
			strcat(full_path,"/");
	}

	// Delete array
	for(int i =0; i < count; ++i) {
		free(string_array[i]);
	}
	free(string_array);

	return full_path;
}

void stop (Dir* target) {
	release_memory(target);
}

void tree (Dir* target, int level) {
	
	if(target) {
		// Current directory name
		for(int i = 0; i < level - 1; ++i)
			printf("    ");
		printf("%s\n", target->name);

		// Other directories
		if(target->head_children_dirs)
			tree(target->head_children_dirs, level + 1);
		
		// Files
		File* start = target->head_children_files;
		while(start) {
			for(int i = 0; i < 4 * level; ++i)
				printf(" ");
			printf("%s\n", start->name);
			start = start->next;
		}
		
		tree(target->next, level);
	}
}

void mv(Dir* parent, char *oldname, char *newname) {
	printf("Execute mv!\n");
}