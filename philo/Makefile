# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 09:03:34 by seonggoc          #+#    #+#              #
#    Updated: 2024/01/04 11:47:06 by seonggoc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS = philo.c \
		srcs/init.c \
		srcs/thread.c \
		srcs/monitor.c \
		util/check_validation.c \
		util/error_handler.c \
		util/util.c \
		util/libft_util.c

OBJS = $(SRCS:.c=.o)
CC = CC
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) $(READLINE_INC) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE)

.PHONY: all clean fclean re
