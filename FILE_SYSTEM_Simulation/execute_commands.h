#ifndef _EXECUTE_COMMANDS_H
#define _EXECUTE_COMMANDS_H

#pragma once

#include "support.h"

// Create a file
void touch(Dir *parent, char *name);

// Create a directory
void mkdir(Dir *parent, char *name);

// List the items in the current directory
void ls(Dir *parent);

// Remove a file
void rm(Dir *parent, char *name);

// Remove a directory
void rmdir(Dir *parent, char *name);

// Change directory
void cd(Dir **target, char *name);

// Show current path
char *pwd(Dir *target);

// Stop the program and release the memory
void stop(Dir *target);

// Print all the directories and files in a tree structure
void tree(Dir *target, int level);

// Change the name of a file / directory
void mv(Dir *parent, char *oldname, char *newname);

#endif // _EXECUTE_COMMANDS_H
