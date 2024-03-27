CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
SRC = 1-main.c 0-binary_tree_node.c binary_tree_print.c 1-binary_tree_insert_left.c
OBJ = $(SRC:.c=.o)
NAME = out
RM = rm -f

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) *~ $(NAME)

oclean:
	$(RM) $(OBJ)

fclean: clean oclean

re: fclean all
