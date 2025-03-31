# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggoy <ggoy.student@42nice.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 12:05:39 by ggoy              #+#    #+#              #
#    Updated: 2025/03/31 15:30:37 by ggoy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
BONUS		= checker
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g3
CC			= cc
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[38;5;153m
NC = \033[0m

SRCS =	lst_utils.c\
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

SRCS_BONUS = get_next_line.c\
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

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

TARGET = $(NAME)
ifeq ($(MAKECMDGOALS), bonus)
	TARGET = $(NAME_BONUS)
endif

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LDFLAGS) $(INCLUDES)
	@echo "\033[1A\033[2K\033[1A"
	@echo "│$(GREEN) Compilation of $(NAME) completed ✓ $(NC)	       │"
	@echo "└──────────────────────────────────────────────┘"
	@$(RM) errors.tmp

$(NAME_BONUS): $(LIBFT) $(OBJS_BONUS)
	@$(CC) $(FLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(LDFLAGS) $(SDL_FLAGS) $(INCLUDES)
	@echo "\033[1A\033[2K\033[1A"
	@echo "│$(GREEN) Compilation of $(NAME_BONUS) completed ✓ $(NC)      │"
	@echo "└──────────────────────────────────────────────┘"
	@$(RM) errors.tmp

.c.o:
	@if [ "$(TARGET)" = "$(NAME)" ] && [ ! -f .mandatory ]; then \
		echo "$(NC)┌─────$(NAME)────────────────────────────────┐"; \
		echo "│$(BLUE) Compiling $(NAME) in progress... ⌛$(NC)	       │"; \
		echo "\033[s└──────────────────────────────────────────────┘"; \
		touch .mandatory; \
	elif [ "$(TARGET)" = "$(NAME_BONUS)" ] && [ ! -f .bonus ]; then \
		echo "$(NC)┌─────$(NAME_BONUS)──────────────────────────┐"; \
		echo "│$(BLUE) Compiling $(NAME_BONUS) in progress... ⌛$(NC)      │"; \
		echo "\033[s└──────────────────────────────────────────────┘"; \
		touch .bonus; \
	fi
	@$(CC) $(FLAGS) -c -o $@ $< $(INCLUDES) 2>> errors.tmp || \
	{ \
		echo "\033[u\033[1A\033[2K│$(RED) Compilation of $(NAME) failed X$(NC)                │"; \
		echo "└──────────────────────────────────────────────┘"; \
		sed "s/error:/\x1b[1;31m&\x1b[0m/g" errors.tmp; \
		$(RM) errors.tmp; \
		exit 1; \
	}

all: $(NAME)
	@$(RM) .mandatory

bonus: $(NAME_BONUS)
	@$(RM) .bonus

checker_linux:
	wget https://cdn.intra.42.fr/document/document/25656/checker_linux
	chmod 777 checker_linux

clean:
	@echo "$(NC)┌─────clean $(NAME)──────────────────────────┐"
	@echo "│$(BLUE) Cleaning $(NAME) objects in progress... ⌛$(NC) │"
	@echo "└──────────────────────────────────────────────┘"
	@sleep 0.8
	@echo "\033[1A\033[2K\033[1A"
	@$(RM) $(OBJS) .mandatory $(OBJS_BONUS) .bonus
	@echo "│$(GREEN) Cleaning of $(NAME) objects completed ✓ $(NC)   │"
	@echo "└──────────────────────────────────────────────┘"

fclean: clean
	@echo "$(NC)┌─────fclean $(NAME)─────────────────────────┐"
	@echo "│$(BLUE) Cleaning $(NAME) in progress... ⌛$(NC)	       │"
	@echo "└──────────────────────────────────────────────┘"
	@sleep 0.8
	@echo "\033[1A\033[2K\033[1A"
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo "│$(GREEN) Cleaning of $(NAME) completed ✓ $(NC)	       │"
	@echo "└──────────────────────────────────────────────┘"

re: fclean all

rebonus: fclean bonus

norme:
	@echo "$(BLUE)Checking norminette in progress... ⌛"
	@if norminette srcs includes libft > norme.tmp;\
	then echo "$(GREEN)Norminette check passed successfully ✓";\
	else echo "$(RED)Norminette check failed.$(NC)";\
	cat norme.tmp | grep "Error";\
	fi
	@$(RM) norme.tmp

.PHONY: all bonus clean fclean re rebonus norme