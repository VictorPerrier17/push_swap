CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	main/push_swap.c \
		main/check.c \
		main/check2.c \
		main/ft_split.c \
		instructions/swap_first_two.c \
		instructions/swap_first_last.c \
		instructions/swap_last_first.c \
		instructions/pa_pb.c \
		three.c \
		power.c \
		two_and_five.c \
		utils.c \
		utils_struct.c \
		algo/algo.c \
		algo/biggest.c \
		algo/a_in_b.c \
		algo/push_biggest.c \
		algo/utils_algo.c \

OBJ =	main/push_swap.o \
		main/ft_split.o \
		main/check.o \
		main/check2.o \
		instructions/swap_first_two.o \
		instructions/swap_first_last.o \
		instructions/swap_last_first.o \
		instructions/pa_pb.o \
		three.o \
		power.o \
		two_and_five.o \
		utils.o \
		utils_struct.o \
		algo/algo.o \
		algo/biggest.o \
		algo/a_in_b.o \
		algo/push_biggest.o \
		algo/utils_algo.o \

NAME = push_swap

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
