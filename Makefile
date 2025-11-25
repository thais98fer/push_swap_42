# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 16:35:20 by thfernan          #+#    #+#              #
#    Updated: 2025/11/20 16:35:24 by thfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -Wall -Wextra -Werror -g3 -I libft
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
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
