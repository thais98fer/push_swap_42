NAME = push_swap
FLAGS = -Wall -Wextra -Werror -g3 -I
CC = cc

LIBFT_A = libft/libft.a
LIBFT_DIR = libft

# push_swap.c
SRCS = main.c

OBJS = $(SRCS:.c=.o)

#==================================================#
#                      rules                       #
#==================================================#
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(OBJS) $(LIBFT_A) -o $(NAME) 
	
$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR) all

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
