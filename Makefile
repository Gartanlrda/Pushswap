# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 12:05:39 by ggoy              #+#    #+#              #
#    Updated: 2024/07/18 11:38:54 by ggoy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#######################       ARGUMENTS         ################################
################################################################################

NAME		= push_swap
CFLAGS		= -Wall -Wextra -Werror
CC		= cc
################################################################################
#######################         SOURCES         ################################
################################################################################

SRC_FILES	= lst_utils.c\
			main.c\
			push.c\
			pushswap_utils1.c\
			pushswap_utils2.c\
			pushswap_utils3.c\
			pushswap_utils4.c\
			pushswap_utils5.c\
			pushswap_utils6.c\
			pushswap_utils7.c\
			reverse_rotate.c\
			rotate.c\
			swap.c\
			ft_printf.c\
			ft_utils1.c

OBJ_FILES	= $(SRC_FILES:.c=.o)

################################################################################
#######################          RULES          ################################
################################################################################


all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES)
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

checker:
	wget https://cdn.intra.42.fr/document/document/25656/checker_linux
	chmod 777 checker_linux
clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
