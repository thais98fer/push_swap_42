# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 16:35:20 by thfernan          #+#    #+#              #
#    Updated: 2025/12/20 17:15:05 by thfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

PS_HDR = push_swap.h
BONUS_HDR = bonus/push_swap_bonus.h

FLAGS = -Wall -Wextra -Werror -g3 -I libft -I . -I bonus
CC = cc

LIBFT_A = libft/libft.a
LIBFT_DIR = libft

BONUS_DIR = bonus

#=================================================================#
#                         push_swap sources                       #
#=================================================================#

SRCS = push_swap.c check_args.c push.c \
       reverse_rotate.c rotate.c swap.c \
	   execute_moves.c cost_moves.c \
	   find_target.c free_error.c count_args.c \
	   limits.c

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = check_args_bonus.c checker_bonus.c \
			count_args_bonus.c free_error_bonus.c \
			limits_bonus.c push_bonus.c reverse_rotate_bonus.c \
			rotate_bonus.c swap_bonus.c

BONUS_SRC_PATH = $(addprefix $(BONUS_DIR)/, $(BONUS_SRCS))
BONUS_OBJS = $(BONUS_SRC_PATH:.c=.o)

#=================================================================#
#                              rules                              #
#=================================================================#

# Colors
RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m

all: $(NAME)
	@echo "$(GREEN)push_swap ready"

$(OBJS): $(PS_HDR)
$(BONUS_OBJS): $(BONUS_HDR)

$(NAME): $(OBJS) $(LIBFT_A)
	@$(CC) $(OBJS) $(LIBFT_A) -o $(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR) all

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS) $(LIBFT_A)
	@$(CC) $(BONUS_OBJS) $(LIBFT_A) -o $(BONUS)
	@echo "$(GREEN)checker ready"

%.o: %.c
	@echo "$(YELLOW)Compiling $<$(RESET)"
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@rm -f *.o
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME) $(BONUS)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all bonus clean fclean re
