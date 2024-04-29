# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 10:33:13 by dparada           #+#    #+#              #
#    Updated: 2024/04/25 12:16:28 by malena-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
USER = malena-b
LIBFT = ./libft
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = src/
OBJ_DIR = obj/
B_SRC_DIR = Bonus/

DEF_COLOR	= \033[0;39m
MAGENTA		= \033[0;35m
YELLOW		= \033[0;33m
GREEN		= \033[0;32m
WHITE		= \033[0;37m
RESET		= \033[0m
GRAY		= \033[0;90m
BLUE		= \033[0;34m
CYAN		= \033[0;37m
RED			= \033[0;31m
BOLD		= \033[1m

SRC_FILES = main check_arg utils lft_mod free_fts stack_op sort_and_index \
	op_calls node_values_calc node_values_calc2
BONUS_FILES = checker_bonus check_arg_bonus free_fts_bonus lft_mod_bonus \
	op_calls_bonus stack_op_bonus utils_bonus

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
BONUS_SRC = $(addprefix $(B_SRC_DIR), $(addsuffix .c, $(BONUS_FILES)))
BONUS_OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(BONUS_FILES)))

OBJF = .cache_exists

all: $(NAME)

$(NAME):	compiling	$(OBJ)
	@make all -C $(LIBFT)
	@echo
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -o $(NAME)
	@echo "$(GREEN)COMPLETE!$(RESET)"
	@echo

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@echo "$(MAGENTA)COMPILING...		$(BLUE)$(notdir $<)$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(B_SRC_DIR)%.c | $(OBJF)
	@echo "$(MAGENTA)COMPILING...		$(BLUE)$(notdir $<)$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)

compiling:
	@echo "$(YELLOW)COMPILING PUSH_SWAP FILES:$(RESET)"

clean:
	@rm -frf $(OBJ_DIR)
	@make clean -C $(LIBFT)

fclean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)
	@rm -rf $(BONUS_NAME)
	@make fclean -C $(LIBFT)
	@echo "$(YELLOW)Push_swap fclean: 	$(GREEN)[COMPLETED]$(EC)"
	@echo

re: fclean all
	@echo "$(YELLOW)PUSH_SWAP: $(GREEN)[RECOMPILED]$(RESET)"

norm:
	@echo "Norminette of push_swap files: "
	@norminette $(SRC_DIR)
	@norminette $(B_SRC_DIR)
	@echo
	@echo "Norminette of libft files: "
	@norminette $(LIBFT)
	@echo

bonus: $(BONUS_OBJ)
			@make -C $(LIBFT)
			@$(CC) $(CFLAGS) $(BONUS_OBJ) -L$(LIBFT) -lft -o $(BONUS_NAME)
			@echo "$(GREEN)BONUS COMPLETE!$(RESET)"
			@echo
.PHONY: all clean fclean re norm compiling bonus

