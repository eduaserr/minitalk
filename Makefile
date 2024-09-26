# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 13:31:38 by eduaserr          #+#    #+#              #
#    Updated: 2024/09/26 16:36:45 by eduaserr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
CLIENT	= client
SERVER	= server
LIBFT	= lib/
INCLUDE	= -L ./lib -lft

CC		= clang
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

### SRC ###
SRC_C	= src/client.c
SRC_S	= src/server.c

### OBJ ###
OBJ_C	= $(SRC_C:.c=.o)
OBJ_S	= $(SRC_S:.c=.o)

### RULES ###
all : $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_C)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_C) -o $(CLIENT) $(INCLUDE)
	@echo "client compiled successfully"

$(SERVER): $(OBJ_S)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_S) -o $(SERVER) $(INCLUDE)
	@echo "server compiled successfully"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_C) $(OBJ_S)
	@make clean -C $(LIBFT)

fclean: clean
	@$(RM) $(CLIENT) $(SERVER)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re bonus