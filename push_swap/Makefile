# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/20 19:21:29 by ggaritta          #+#    #+#              #
#    Updated: 2026/04/23 21:29:09 by ggaritta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
BONUS_NAME	= checker

CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

SRCS		= push_swap.c \
		  ft_moves.c \
		  ft_qops.c \
		  ft_split.c \
		  ft_parser.c \
		  ft_error.c \
		  ft_libft.c \
		  ft_lis.c \
		  ft_sorting_utilities.c \
		  ft_sortini.c

OBJS		= $(SRCS:.c=.o)

#If bonus checker files exist, they are built into it.
BONUS_SRCS	= $(wildcard checker*.c)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

ifneq ($(BONUS_SRCS),)
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)
else
bonus: all
	@echo "No bonus checker sources found (expected checker*.c)."
endif

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re