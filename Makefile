# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/09 14:33:29 by irhett            #+#    #+#              #
#    Updated: 2017/04/09 18:01:57 by irhett           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	ft_contrast

CC					=	gcc
CFLAGS				=	-Wall -Werror -Wextra
XFLAGS				=	-pthread
FLAGS				=	$(CFLAGS) $(XFLAGS)

SRC_DIR				=	src
						########################################################
SRC_FILE			=	ft_contrast.c threads.c 
						########################################################
SRCS				=	$(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJ_DIR				=	obj
OBJ_FILE			=	$(SRC_FILE:.c=.o)
OBJS				=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILE))

LIBDIR				=	lib

LIBFT_THPOOL_DIR	=	$(LIBDIR)/libft_thpool
LIBFT_THPOOL_LIB	=	libft_thpool.a
LIBFT_THPOOL_INC	=	$(LIBFT_THPOOL_DIR)/inc
LIBFT_THPOOL		=	$(LIBFT_THPOOL_DIR)/$(LIBFT_THPOOL_LIB)

LIBFT_DIR			=	$(LIBDIR)/libft
LIBFT_LIB			=	libft.a
LIBFT_INC			=	$(LIBFT_DIR)/includes
LIBFT				=	$(LIBFT_DIR)/$(LIBFT_LIB)

INC_DIR				=	-I $(LIBFT_INC) -I $(LIBFT_THPOOL_INC) -I inc

.PHONY: lib all clean fclean re

all: $(LIBFT_THPOOL) $(LIBFT) $(NAME)

$(NAME): $(SRCS) | $(OBJS)
	$(CC) $(FLAGS) $(LIBFT_THPOOL) $(LIBFT) $(OBJS) $(INC_DIR) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) -c $^ $(CFLAGS) $(INC_DIR) -o $@

clean:
	@cd $(LIBFT_THPOOL_DIR) && make clean
	@cd $(LIBFT_DIR) && make clean
	@rm -rf $(OBJ_DIR)

fclean:
	@cd $(LIBFT_THPOOL_DIR) && make fclean
	@cd $(LIBFT_DIR) && make fclean
	@rm -f $(NAME)

re: fclean all

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(LIBFT_THPOOL):
	@$(MAKE) -C $(LIBFT_THPOOL_DIR)
