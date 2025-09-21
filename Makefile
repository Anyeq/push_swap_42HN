# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asando <asando@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/17 16:44:37 by asando            #+#    #+#              #
#    Updated: 2025/09/21 17:26:43 by asando           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compiler flag
CC ?= cc
DEBUG ?= 0

# include folder
HEADER = includes
LIBFT_HEADER = ./lib/libft/include

CFLAGS = -Wall -Werror -Wextra -I$(HEADER) -I$(LIBFT_HEADER)

ifeq ($(DEBUG), 1)
	CFLAGS += -g -O0
endif

# source folder
SRC_DIR = src

# sub source folder
OPERATION_FUNC_DIR = $(SRC_DIR)/operation
ALGORITHM_FUNC_DIR = $(SRC_DIR)/algorithm
BONUS_FUNC_DIR = $(SRC_DIR)/bonus
MAIN_FUNC_DIR = $(SRC_DIR)/main_function 

# Files to be compiled
OPERATION_FUNC_FILES = swap.c push.c rotate.c reverse_rotate.c
ALGORITHM_FUNC_FILES = turk_algorithm.c turk_init_utils.c \
					   turk_move_utils.c turk_optimizer.c
MAIN_FUNC_FILES = grab_arg.c stack_utils.c
BONUS_FUNC_FILES = checker_bonus.c
MAIN = main.c

# path to files
SRC_OPERATION = $(addprefix $(OPERATION_FUNC_DIR)/, $(OPERATION_FUNC_FILES))
SRC_ALGORITHM = $(addprefix $(ALGORITHM_FUNC_DIR)/, $(ALGORITHM_FUNC_FILES))
SRC_MAIN_FUNC = $(addprefix $(MAIN_FUNC_DIR)/, $(MAIN_FUNC_FILES))
SRC_BONUS_FUNC = $(addprefix $(BONUS_FUNC_DIR)/, $(BONUS_FUNC_FILES))
SRC_MAIN = $(addprefix $(SRC_DIR)/, $(MAIN))
ALL_SRCS = $(SRC_OPERATION) $(SRC_ALGORITHM) $(SRC_MAIN_FUNC) $(SRC_MAIN)

# obj directory
OBJ_DIR = obj
BONUS_OBJ_DIR = obj_bonus

# obj files
OBJ_OPERATION = $(OPERATION_FUNC_FILES:%.c=$(OBJ_DIR)/%.o)
OBJ_ALGORITHM = $(ALGORITHM_FUNC_FILES:%.c=$(OBJ_DIR)/%.o)
OBJ_MAIN_FUNC = $(MAIN_FUNC_FILES:%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS_FUNC = $(BONUS_FUNC_FILES:%.c=$(BONUS_OBJ_DIR)/%.o)
OBJ_BONUS_OPERATION = $(OPERATION_FUNC_FILES:%.c=$(BONUS_OBJ_DIR)/%.o)
OBJ_BONUS_MAIN_FUNC = $(MAIN_FUNC_FILES:%.c=$(BONUS_OBJ_DIR)/%.o)
OBJ_MAIN = $(MAIN:%.c=$(OBJ_DIR)/%.o)
ALL_OBJS = $(OBJ_OPERATION) $(OBJ_ALGORITHM) $(OBJ_MAIN_FUNC) $(OBJ_MAIN)
ALL_BONUS_OBJS = $(OBJ_BONUS_OPERATION) $(OBJ_BONUS_MAIN_FUNC) \
				 $(OBJ_BONUS_FUNC)

# library directory
LIBFT_DIR = ./lib/libft
FT_PRINTF_DIR = ./lib/libft/src/ft_printf

# Archive target
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = libftprintf.a

NAME = push_swap
NAME_CHECKER = checker

all: $(NAME)
	@echo "Program is Compiled"

$(NAME): $(ALL_OBJS) $(LIBFT)
	@echo "All Object Files are ready"
	@$(CC) $(CFLAGS) -o $@ $^ -L$(FT_PRINTF_DIR) -lftprintf -L$(LIBFT_DIR) -lft

$(NAME_CHECKER): $(ALL_BONUS_OBJS) $(LIBFT)
	@echo "All Bonus Object Files are ready"
	@$(CC) $(CFLAGS) -o $@ $^ -L$(FT_PRINTF_DIR) -lftprintf -L$(LIBFT_DIR) -lft

# virtual path
vpath %.c $(OPERATION_FUNC_DIR)
vpath %.c $(ALGORITHM_FUNC_DIR)
vpath %.c $(MAIN_FUNC_DIR)
vpath %.c $(BONUS_FUNC_DIR)
vpath %.c $(SRC_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: %.c | $(BONUS_OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

#$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
#	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(BONUS_OBJ_DIR):
	@mkdir -p $(BONUS_OBJ_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

bonus: $(BONUS_OBJ_DIR) $(NAME_CHECKER)
	@echo "Bonus Program is Compiled"

clean:
	@rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	@echo "Program deleted"
	@rm -rf $(NAME)
	@rm -rf $(NAME_CHECKER)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re:
	@$(MAKE) fclean
	@$(MAKE) all

debug:
	@$(MAKE) DEBUG=1 re

.PHONY: all clean fclean re debug bonus
