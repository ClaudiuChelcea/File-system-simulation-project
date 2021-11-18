# Chelcea Claudiu 322CA
#
#

# Variables
NAME=tema
CFLAGS=-g
#CFLAGS=-Wall -Wextra -g
CC=gcc
FILES_C=main.c receive_commands.c execute_commands.c support.c
FILES_O=main.o receive_commands.o execute_commands.o support.o

# Rules 
all: $(NAME)

$(NAME): $(FILES_O)
	$(CC) -o $(NAME) $(FILES_O) $(CFLAGS)

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

receive_commands.o: receive_commands.c
	$(CC) -c receive_commands.c $(CFLAGS)

execute_commands.o: execute_commands.c
	$(CC) -c execute_commands.c $(CFLAGS)

support.o: support.c
	$(CC) -c support.c $(CFLAGS)

clean:
	rm *.o
	rm $(NAME)

.PHONY: clean
	
checker:
	python3 checker.py
