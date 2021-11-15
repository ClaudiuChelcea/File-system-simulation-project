#include "receive_commands.h"

int main(void) {
    
    // Input
    char* command = NULL;
    command = calloc(MAX_COMMAND_LENGTH, sizeof(char));
    DIE(command, "Couldn't allocate memory for receiving commands!");

    while(true) {
        scanf("%s", command);
        scan_and_execute_command(recognize_command(command));
    }

    // Release memory
    release_memory(command);

    return 0;
}