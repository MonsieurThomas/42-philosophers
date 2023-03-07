# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 12:49:39 by rthomas           #+#    #+#              #
#    Updated: 2022/06/22 12:38:12 by rthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philosophers

CFLAGS = -Wall -Wextra -Werror 

SOURCES =	src/main.c \
			src/utils.c \
			src/utils2.c \
			src/init.c \
			src/print_func.c \
			src/check_value.c \
			src/pthread.c

OBJS = $(SOURCES:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			gcc $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

norme:
			norminette $(SRCS)

re:			fclean all

.PHONY:		re clean fclean all libft