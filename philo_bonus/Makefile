# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 16:22:21 by ereginia          #+#    #+#              #
#    Updated: 2022/03/23 14:05:10 by ereginia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = philo_bonus

FLAGS = -Wall -Wextra -Werror

SRCS_M =	init.c\
			libft_list_1.c\
			libft_list_2.c\
			overwatch.c\
			parser.c\
			philo_bonus.c\
			routine.c\
			utils.c

M_HEADER = philo_bonus.h

OBJS_M = $(SRCS_M:.c=.o)

$(NAME): $(OBJS_M) $(M_HEADER)
	$(CC) $(FLAGS) $(OBJS_M) -o $(NAME)

all: $(NAME)

%.o: %.c	$(M_HEADER) Makefile
			$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_M)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

PHONY: all bonus clean fclean re
