#ifndef _SUPPORT_H
#define _SUPPORT_H

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_LINE_SIZE 300

#pragma once // depinde de arhitectura daca recunoaste garzile, asa ca folosim si pragma

#define DIE(condition,msg)                                                                \
if(condition) {                                                                           \
    printf("Error at line %d in file %s!\n",__LINE__, __FILE__);                          \
    printf("Your message: %s\n", msg);                                              	  \
    exit(-1);                                                                             \
}

typedef struct Dir{
	char *name;   // numele directorului
	struct Dir* parent;  // pointer catre parintele directorului(null pentru radacina)
	struct File* head_children_files;  // pointer catre primul element de tip File din interiorul directorului
	struct Dir* head_children_dirs; // pointer catre primul element de tip Dir din interiorul directorului
	struct Dir* next; // pointer catre urmatorul element din lista in care se afla directorul
} Dir; // structura de tip director
 
typedef struct File {
	char *name;  // numele fisierului
	struct Dir* parent; // pointer catre directorul parinte
	struct File* next; // pointer catre urmatorul element din lista de fisiere
} File; // structura de tip fisier

/* Support functions */

// Create a default directory
Dir* default_directory ();

// Create a default directory
File* default_file (Dir* parent, char* file_name);

// Release the memory
void release_memory (Dir* root_directory);

// Release a whole directory
void release_directory(Dir* directory_name);



#endif