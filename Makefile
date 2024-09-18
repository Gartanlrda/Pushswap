# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 12:05:39 by ggoy              #+#    #+#              #
#    Updated: 2024/08/31 13:40:01 by ggoy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#######################       ARGUMENTS         ################################
################################################################################

NAME		= push_swap
BONUS		= checker
CFLAGS		= -Wall -Wextra -Werror #-fsanitize=address -g
CC			= cc
################################################################################
#######################         SOURCES         ################################
################################################################################

SRC_FILES		= lst_utils.c\
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

SRC_FILES_BONUS	= get_next_line.c\
				get_next_line_utils.c\
				main_bonus.c\
				push_swap_bonus.c\
				bonus_instructions1.c\
				bonus_instructions2.c\
				bonus_instructions3.c\
				ft_printf.c\
				pushswap_utils1.c\
				pushswap_utils2.c\
				ft_utils1.c\
				lst_utils.c

OBJ_FILES		= $(SRC_FILES:.c=.o)

OBJ_FILES_BONUS	= $(SRC_FILES_BONUS:.c=.o)

################################################################################
#######################          RULES          ################################
################################################################################


all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

bonus: $(BONUS)

$(BONUS): $(OBJ_FILES_BONUS)
	$(CC) $(CFLAGS) -o $(BONUS) $(OBJ_FILES_BONUS)

checker_linux:
	wget https://cdn.intra.42.fr/document/document/25656/checker_linux
	chmod 777 checker_linux
clean:
	rm -f $(OBJ_FILES) $(OBJ_FILES_BONUS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re
