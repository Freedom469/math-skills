CC = gcc
SRC = main.c ./utils/sort.c ./utils/variance.c
OBJ = $(SRC:.c=.o)

program : $(OBJ)
	$(CC) -o program $(OBJ) -lm

%.o : %.c
	$(CC) -c $< -o $@

clean:
	rm -f program $(OBJ)