# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cuzureau <cuzureau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 11:57:12 by cuzureau          #+#    #+#              #
#    Updated: 2018/01/08 14:56:49 by cuzureau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
CC			=	gcc
CFLAGS		+=	-Wall -Wextra -Werror

LFT_PATH	=	./libft/
OBJ_PATH	=	./obj/
SRC_PATH	=	./src/

INC_NAME	=	minishell.h 
OBJ_NAME	=	$(SRC_NAME:.c=.o)
SRC_NAME	=	main.c

INC			=	-I ./include -I ./libft/include/
SRC			=	$(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))

all				: $(NAME)

$(NAME)			:	$(OBJ)
					@make -C $(LFT_PATH)
					@$(CC) -o $(NAME) -L $(LFT_PATH) -lft $^ -o $@
					# @echo "\n   	#Created by: cuzureau <cuzureau@student.42.fr>\n\ #
   	#Powered by: ██╗     ██╗██████╗ ███████╗████████╗\n\
   	             ██║     ██║██╔══██╗██╔════╝╚══██╔══╝\n\
   	             ██║     ██║██████╔╝█████╗     ██║\n\
   	             ██║     ██║██╔══██╗██╔══╝     ██║\n\
   	             ███████╗██║██████╔╝██║        ██║\n\
   	             ╚══════╝╚═╝╚═════╝ ╚═╝        ╚═╝\n";

$(OBJ_PATH)%.o	:	$(SRC_PATH)%.c
					@mkdir -p $(OBJ_PATH) 2> /dev/null || true
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@
					# @echo "# ****************************************************************************** #\n
#                                                                                #\n\
#   ███╗   ███╗ ██╗ ███╗   ██╗ ██╗ ███████╗ ██╗  ██╗ ███████╗ ██╗      ██╗       #\n\
#   ████╗ ████║ ██║ ████╗  ██║ ██║ ██╔════╝ ██║  ██║ ██╔════╝ ██║      ██║       #\n\
#   ██╔████╔██║ ██║ ██╔██╗ ██║ ██║ ███████╗ ███████║ █████╗   ██║      ██║       #\n\
#   ██║╚██╔╝██║ ██║ ██║╚██╗██║ ██║ ╚════██║ ██╔══██║ ██╔══╝   ██║      ██║       #\n\
#   ██║ ╚═╝ ██║ ██║ ██║ ╚████║ ██║ ███████║ ██║  ██║ ███████╗ ███████╗ ███████╗  #\n\
#   ╚═╝     ╚═╝ ╚═╝ ╚═╝  ╚═══╝ ╚═╝ ╚══════╝ ╚═╝  ╚═╝ ╚══════╝ ╚══════╝ ╚══════╝  #\n\
#                                                                                #\n\
# ****************************************************************************** #";

clean			: 
					@make -C $(LFT_PATH) clean
					@rm -rf $(OBJ_PATH)

fclean			:	clean
					@make -C $(LFT_PATH) fclean
					@rm -f $(NAME)

re				:	fclean all

.PHONY			:	all clean