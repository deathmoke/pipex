SRCS = error_control.c ft_split.c pipex.c pipex_utilis.c search_paths.c
	 

SRCS_BONUS = error_control_bonus.c ft_split.c pipex_bonus.c \
			pipex_utilis_bonus.c search_paths.c

OBJ = $(SRCS:.c=.o)

OBJ_BONUS = $(SRCS_BONUS:.c=.o)

NAME = pipex

BONUS = pipex_bonus

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: $(BONUS)

CC = gcc

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -I ./

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -I ./

$(BONUS): $(OBJ_BONUS)
	$(CC) $(FLAGS) -o $(BONUS) $(OBJ_BONUS) -I ./

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME) $(BONUS)

re: fclean all
