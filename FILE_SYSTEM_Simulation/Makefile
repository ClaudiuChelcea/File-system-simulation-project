# Chelcea Claudiu 322CA
#
#

# Variables
NAME=EXEC
CLAGS=-Wall -Wextra
CC=gcc
FILES_C=main.c receive_commands.c
FILES_O=main.o receive_commands.o

# Rules 
all:EXEC

EXEC:$(FILES_O)
	$(CC) -o $(NAME) $(FILES_C) $(CFLAGS)

main.o: main.c
	$(CC) -c main.c

receive_commands.o: receive_commands.c
	$(CC) -c receive_commands.c

clean:
	rm *.o
	rm $(NAME)

.PHONY: clean
	
