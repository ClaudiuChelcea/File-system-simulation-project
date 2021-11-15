#include "receive_commands.h"

// Scan inputs based on the command and execute it
void scan_and_execute_command(int command_number) {
    switch(command_number) {
        case 1:
            printf("Execute touch!");
            break;
        case 2:
            printf("Execute mkdir!");
            break;
        case 3:
            printf("Execute ls!");
            break;
        case 4:
            printf("Execute rm!");
            break;
        case 5:
            printf("Execute rmdir!");
            break;
        case 6:
            printf("Execute cd!");
            break;
        case 7:
            printf("Execute tree!");
            break;
        case 8:
            printf("Execute pwd!");
            break;
        case 9:
            printf("Execute stop!");
            break;
        case -1:
            printf("Command not recognized!\n");
            break;
        default:
            printf("Other output than expected!");
            return;
    }
}

// Recognize the command and return an id for it
int recognize_command(char* command) {
    if(strcmp(command, "touch")==0)
        return 1;
    else if(strcmp(command, "mkdir")==0)
        return 2;
    else if(strcmp(command, "ls") ==0)
        return 3;
    else if(strcmp(command, "rm") ==0)
        return 4;
    else if(strcmp(command, "rmdir")==0)
        return 5;
    else if(strcmp(command, "cd") == 0)
        return 6;
    else if(strcmp(command, "tree") ==0)
        return 7;
    else if(strcmp(command, "pwd") ==0)
        return 8;
    else if(strcmp(command, "stop") == 0)
        return 9;
    else
        return -1;
}

// Release the memory
void release_memory(char* command) {
    free(command);
}
