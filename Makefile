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

NAME = push_swap

FILE = insert2_utils.c insert_utils.c  resolve5.c      resolver.c      resolverb.c     utils.c         utils3.c\
       insert3_utils.c main2.c         resolve5_rev.c  resolvera.c     save.c          utils2.c

FILE_BONUS = bonus.c	 insert_utils_bonus.c insert_utils_bonus_2.c  insert_utils_bonus_3.c \
			insert2_utils.c insert_utils.c  resolve5.c      resolver.c      resolverb.c     utils.c         utils3.c\
                   insert3_utils.c         resolve5_rev.c  resolvera.c     save.c          utils2.c


GNL_DIRECTORY = get_next_line/

GNL = $(GNL_DIRECTORY)gnl.a

LIBFT_DIRECTORY = libft/

LIBFT = $(LIBFT_DIRECTORY)libft.a


FLAGS = -Wall -Wextra -Werror

FLAGS =

HEADERS = includes

SOURCES_DIRECTORY = src/

OBJECTS_DIRECTORY = obj/

SRCS = $(addprefix $(SOURCES_DIRECTORY), $(FILE))

OBJS = $(addprefix $(OBJECTS_DIRECTORY), $(FILE:.c=.o))

OBJS_BONUS = $(addprefix $(OBJECTS_DIRECTORY), $(FILE_BONUS:.c=.o))

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c
	gcc  $(FLAGS) -I $(HEADERS) -c $< -o $@

all:$(NAME)

bonus: $(GNL) $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJS_BONUS)
	gcc $(FLAGS) -I $(HEADERS) $(LIBFT) $(OBJS_BONUS) $(GNL) -o checker

$(LIBFT):
	@echo "make libft"
	@make -sC $(LIBFT_DIRECTORY)
	@make bonus -sC $(LIBFT_DIRECTORY)

$(GNL):
	@echo "make gnl"
	@make -sC $(GNL_DIRECTORY)

$(OBJECTS_DIRECTORY):
	mkdir -p $@

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJS)
	gcc $(FLAGS) -I $(HEADERS) $(LIBFT) $(OBJS) -o ${NAME}

clean:
	@make fclean -sC $(LIBFT_DIRECTORY)
	@make fclean -sC $(GNL_DIRECTORY)
	rm -Rf $(OBJECTS_DIRECTORY)

fclean: clean
	rm -f $(NAME)

re: fclean all

exe: all
	./push_swap 154 376 -445 -748 -313 435 -40 595 -850 62

.PHONY: all clean fclean re