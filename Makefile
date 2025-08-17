# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asando <asando@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/17 16:44:37 by asando            #+#    #+#              #
#    Updated: 2025/08/17 21:55:34 by asando           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC ?= cc

HEADER = includes

LIBFT_HEADER = ./lib/libft/include

DEBUG ?= 0

CFLAGS = -Wall -Werror -Wextra -I$(HEADER) -I$(LIBFT_HEADER)

ifeq ($(DEBUG), 1)
	CFLAGS += -g -O0
endif

MAIN = main.c

SRC_DIR = src

SRCS = grab_arg.c stack_utils.c

SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ_DIR = obj

OBJ_FILES = $(SRCS:%.c=$(OBJ_DIR)/%.o)

OBJ_MAIN = $(MAIN:%.c=$(OBJ_DIR)/%.o)

ALL_OBJS = $(OBJ_FILES) $(OBJ_MAIN)

LIBFT_DIR = ./lib/libft

FT_PRINTF_DIR = ./lib/libft/src/ft_printf

LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF = libftprintf.a

NAME = push_swap

all: $(NAME)
	@echo "Program is Compiled"

$(NAME): $(ALL_OBJS) $(LIBFT)
	@echo "All Object Files is ready"
	@$(CC) $(CFLAGS) -o $@ $^ -L$(FT_PRINTF_DIR) -lftprintf -L$(LIBFT_DIR) -lft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	@echo "Program deleted"
	@rm -rf $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
