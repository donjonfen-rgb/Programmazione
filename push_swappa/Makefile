# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/20 19:21:29 by ggaritta          #+#    #+#              #
#    Updated: 2026/05/03 19:56:20 by ggaritta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
BONUS_NAME	= checker

HEADERS = push_swap.h
CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I.

COMMON_SRCS	=	cfiles/ft_error.c \
				cfiles/ft_libft.c \
				cfiles/ft_split.c \
				cfiles/ft_parser.c \
				cfiles/ft_qops.c \
				cfiles/ft_moves.c \
				cfiles/ft_lis.c \
				cfiles/ft_sorting_utilities.c \
				cfiles/ft_sortini.c \
				cfiles/ft_chonkers_utils.c \
				cfiles/ft_chonkers.c \
				cfiles/ft_griddy_utils.c \
				cfiles/ft_griddy.c

SRCS		= cfiles/push_swap.c $(COMMON_SRCS)
BONUS_SRCS	= bonus/checker.c $(COMMON_SRCS)

OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)
#DEPS		= $(OBJS:.o=.d) $(BONUS_OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ -g

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

test: all bonus clean

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re test
