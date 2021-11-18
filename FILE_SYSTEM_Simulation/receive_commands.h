#ifndef __RECEIVE_COMMANDS_H
#define __RECEIVE_COMMANDS_H

#pragma once

#include "support.h"
#include "execute_commands.h"

// Scan inputs based on the command and execute it
bool scan_and_execute_command(int command_number, Dir** current_directory);

// Recognize the command and return an id for it
int recognize_command(char* command);

#endif