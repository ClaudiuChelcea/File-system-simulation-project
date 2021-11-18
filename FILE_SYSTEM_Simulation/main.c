#include "support.h"
#include "receive_commands.h"
#include "execute_commands.h"

int main(void) {
    
    // Input
    char* command = NULL;
    command = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
    DIE(!command, "Couldn't allocate memory for receiving commands!");

    // Current directory
    Dir* directory = default_directory();
    strcat(directory->name, "home");
    
    do {
        scanf("%s", command);
    } while(scan_and_execute_command(recognize_command(command), &directory));

    // Release memory
    free(command);

    return 0;
}