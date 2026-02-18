NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c main_utils.c ft_swap.c ft_simple_algo.c \
ft_rotation.c ft_ra.c ft_push.c ft_medium_algo.c \
ft_medium_algo_utilities.c ft_complex_algo.c ft_adaptive_algo.c compute_disorder.c \
calcul_end_index.c number_parser.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
