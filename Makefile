CC = gcc
SRC = main.c ./utils/sort.c ./utils/variance.c
OBJ = $(SRC:.c=.o)

hello : $(OBJ)
	$(CC) -o hello $(OBJ) -lm

%.o : %.c
	$(CC) -c $< -o $@

clean:
	rm -f hello $(OBJ)