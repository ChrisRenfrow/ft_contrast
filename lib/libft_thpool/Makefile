# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/09 14:34:19 by irhett            #+#    #+#              #
#    Updated: 2017/04/09 16:27:59 by irhett           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft_thpool

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
XFLAGS		=	-pthread	
FLAGS		=	$(CFLAGS) $(XFLAGS)

SRC_DIR		=	src
				################################################################
SRC_FILE	=	##!!##
				################################################################
SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJ_DIR		=	obj
OBJ_FILE	=	$(SRC_FILE:.c=.o)
OBJS		=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILE))

LIBFT_DIR	=	libft
LIBFT_LIB	=	libft.a
LIBFT_INC	=	includes	
LIBFT		=	$(LIBFT_DIR)/$(LIBFT_LIB)

INC_DIR		=	-I $(LIBFT_DIR)/$(LIBFT_INC) -I inc

.PHONY: libft all clean fclean re

all: $(LIBFT) $(NAME)

$(NAME): $(SRCS) | $(OBJS)
	$(CC) $(FLAGS) $(LIBFT) $(OBJS) $(INC_DIR) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) -c $^ $(CFLAGS) $(INC_DIR) -o $@

clean:
	@cd $(LIBFT_DIR) && make clean
	@rm -rf $(OBJ_DIR)

fclean:
	@cd $(LIBFT_DIR) && make fclean
	@rm -f $(NAME)

re: fclean all

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
