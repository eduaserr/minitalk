# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 13:31:38 by eduaserr          #+#    #+#              #
#    Updated: 2024/10/03 16:25:50 by eduaserr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
CLIENT	= client
SERVER	= server
CLIENT_B	= client_bonus
SERVER_B	= server_bonus
LIBFT	= lib/
INCLUDE	= -L ./lib -lft

CC		= clang
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

### SRC ###
SRC_C	= src/client.c src/client_utils.c
SRC_S	= src/server.c

SRC_C_B	= src/client_bonus.c src/client_utils.c
SRC_S_B	= src/server_bonus.c

### OBJ ###
OBJ_C	= $(SRC_C:.c=.o)
OBJ_S	= $(SRC_S:.c=.o)

OBJ_C_B	= $(SRC_C_B:.c=.o)
OBJ_S_B	= $(SRC_S_B:.c=.o)

### RULES ###
all : $(CLIENT) $(SERVER)

bonus : $(CLIENT_B) $(SERVER_B)

$(CLIENT): $(OBJ_C)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_C) -o $(CLIENT) $(INCLUDE)
	@echo "client compiled successfully"

$(SERVER): $(OBJ_S)
	@$(CC) $(CFLAGS) $(OBJ_S) -o $(SERVER) $(INCLUDE)
	@echo "server compiled successfully"

$(CLIENT_B): $(OBJ_C_B)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_C_B) -o $(CLIENT_B) $(INCLUDE)
	@echo "client_bonus compiled successfully"

$(SERVER_B): $(OBJ_S_B)
	@$(CC) $(CFLAGS) $(OBJ_S_B) -o $(SERVER_B) $(INCLUDE)
	@echo "server_bonus compiled successfully"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_C) $(OBJ_S) $(OBJ_C_B) $(OBJ_S_B)
	@make clean -C $(LIBFT)

fclean: clean
	@$(RM) $(CLIENT) $(SERVER) $(CLIENT_B) $(SERVER_B)
	@make fclean -C $(LIBFT)

re: fclean all

rebonus : fclean bonus

.PHONY: all clean fclean re bonus rebonus