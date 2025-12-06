# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 16:35:20 by thfernan          #+#    #+#              #
#    Updated: 2025/12/06 18:37:57 by thfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -Wall -Wextra -Werror -g3 -I libft
CC = cc

LIBFT_A = libft/libft.a
LIBFT_DIR = libft

# push_swap.c
SRCS = push_swap.c check_args.c push.c \
       reverse_rotate.c rotate.c swap.c \
	   execute_moves.c cost_moves.c \
	   find_target.c free_error.c

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
	@rm -f *.o
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
