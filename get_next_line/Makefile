# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acouliba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 14:30:37 by acouliba          #+#    #+#              #
#    Updated: 2021/11/11 16:03:35 by acouliba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

SRCS =  get_next_line_bonus.c       get_next_line_bonus.h       get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS_B = $(BONUS:.c=.o)

FLAGS = -Wall -Wextra -Werror

HEADERS = .

.c.o:
	gcc  ${FLAGS} -D BUFFER_SIZE=42 -I $(HEADERS) -c $< -o ${<:.c=.o}

all: ${NAME}

bonus: $(OBJS_B)
	ar rc ${NAME} ${OBJS_B}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

clean:
	rm -f ${OBJS} ${OBJS_B}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
