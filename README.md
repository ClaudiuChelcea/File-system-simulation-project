The main file is "tema1.c", a simple loop which receives the commands. For each command, it returns a number from 1 - 10 for a valid command or -1 for an invalid command, number that is given to the scan_and_execute_command function, a function represented by a switch block which calls the specific function for the received number.

1
For getting the number 1, the switch block executes the touch function, which creates a file with the given name, after checking that the name isn't already used, case in which it will return an error.

It first compares the received name with the parent directory, then checks if this file will be the first file in the directory and puts it there, or it puts it to the end of the list of files.

2
For number 2, it created a directory with the exact steps as the touch fct described above.

3
FOr number 3, the switch block loops first through all the subdirectories in the current directory and prints their name, after which it will do the same with the files.

4
The rm function will firstly check if we have any files, and, if we do, it will search for it. If the first file needs to be removed, we move the head_children_files to the next file and then remove it, or, if it isn't the first file, it's just a linked list item removal: find the element behind it and then: element->next = element->next->next, thus skipping it, while keeping the element->next in a separate pointer to be able to release the memory.

5
The rmdir function is a copy of the previous rm function, only working with directories.

6
The cd changes the directory. For the ".." input, it checks if we have a parent If yes, the current directory will become the parent directory, otherwise it will do nothing.

For any another input, it will search for it and, if it finds it, the current directory will become that directory, otherwise it will return an error.

7
The pwd function will return the current path by saving the name of the current directory and the name of all the parents of the current directory in a char* (string) array. It will then reverse concatenate all these name to form the current path and will return it.

8
The stop function will release all the memory in the folders and files recursively.

9
The tree function displays all the folders and files: folders first, files last It goes recursively through all the file structure we build, starting from the current directory.

10
The mv function changes the name of a file / directory and moves it to the end of the list.
