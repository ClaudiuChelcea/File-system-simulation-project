#ifndef __RECEIVE_COMMANDS_H
#define __RECEIVE_COMMANDS_H

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_COMMAND_LENGTH 50

#define DIE(ptr,msg)                                                                \
if(!ptr) {                                                                          \
    printf("Error at line %d in file %s!\n",__LINE__, __FILE__);                    \
    printf("Your message: %s\n", msg);                                              \
                                                                                    \
}

// Scan inputs based on the command and execute it
void scan_and_execute_command(int command_number);

// Recognize the command and return an id for it
int recognize_command(char* command);

// Release the memory
void release_memory(char* command);

#endif