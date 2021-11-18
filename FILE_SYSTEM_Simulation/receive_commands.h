#ifndef _RECEIVE_COMMANDS_H
#define _RECEIVE_COMMANDS_H

#pragma once

#include "execute_commands.h"
#include "support.h"

// Scan inputs based on the command and execute it
bool scan_and_execute_command(int command_number, Dir **current_directory);

// Recognize the command and return an id for it
int recognize_command(char *command);

#endif //  _RECEIVE_COMMANDS_H