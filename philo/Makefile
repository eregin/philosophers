# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 14:09:04 by ereginia          #+#    #+#              #
#    Updated: 2022/03/21 14:30:57 by ereginia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = philo

FLAGS = -Wall -Wextra -Werror

SRCS_M =	init.c\
			libft_list_1.c\
			libft_list_2.c\
			overwatch.c\
			parser.c\
			philo.c\
			routine.c\
			utils.c\
			cleaner.c

M_HEADER = philo.h

OBJS_M = $(SRCS_M:.c=.o)

$(NAME): $(OBJS_M) $(M_HEADER)
	$(CC) $(FLAGS) $(OBJS_M) -o $(NAME)

all: $(NAME)

%.o: %.c	$(M_HEADER)
			$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_M)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

PHONY: all bonus clean fclean re
