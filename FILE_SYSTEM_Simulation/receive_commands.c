#include "receive_commands.h"
#define LEVEL 1

// Scan inputs based on the command and execute it
bool scan_and_execute_command(int command_number, Dir** current_directory) {

    // Varibles
    char* file_name = NULL;
    char* dir_name = NULL;
    char* output = NULL;

    switch(command_number) {
        case 1:
            // Get file name
            file_name = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
            DIE(!file_name, "Couldn't read file name in the touch function!");
            scanf("%s", file_name);

            touch(*current_directory, file_name);
            
            break;
        case 2:
            // Get directory name
            dir_name = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
            DIE(!dir_name, "Couldn't read directory name in the mkdir function!");
            scanf("%s", dir_name);

            mkdir(*current_directory, dir_name);
            
            break;
        case 3:
            ls(*current_directory);
            break;
        case 4:
            // Get file name
            file_name = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
            DIE(!file_name, "Couldn't read file name in the touch function!");
            scanf("%s", file_name);

            rm(*current_directory, file_name);

            break;
        case 5:
            // Get directory name
            dir_name = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
            DIE(!dir_name, "Couldn't read directory name in the mkdir function!");
            scanf("%s", dir_name);

            rmdir(*current_directory, dir_name);
            break;
        case 6:
            // Get directory name
            dir_name = calloc(MAX_INPUT_LINE_SIZE, sizeof(char));
            DIE(!dir_name, "Couldn't read directory name in the mkdir function!");
            scanf("%s", dir_name);

            cd(current_directory, dir_name);
            break;
        case 7:
            // GEt level
            if(!(*current_directory)->head_children_dirs)
                break;
            cd(current_directory, (*current_directory)->head_children_dirs->name);
            tree(*current_directory, LEVEL);
            cd(current_directory, "..");
            break;
        case 8:
            output = pwd(*current_directory);
            printf("%s\n", output);
            free(output);
            output = NULL;
            break;
        case 9:
            while((*current_directory)->parent)
                (*current_directory) = (*current_directory)->parent;
            stop(*current_directory);
            return false;
        case -1:
            return true;
        default:
            return true;
    }

    if(file_name) {
        free(file_name);
    }
    if(dir_name) {
        free(dir_name);
    }
    if(output) {
        free(output);
    }

    return true;
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

