# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 16:45:45 by grebrune          #+#    #+#              #
#    Updated: 2024/01/09 19:25:35 by grebrune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		:= 	so_long.c\
				parsing.c\
				parsing_utils.c\
				print_map.c\
				close_win.c\
				game_move.c\
				tab_creator.c\

SRCS_D		:=	src/

OBJS_D		:=	objs/

OBJS		:=	$(SRCS:%.c=$(OBJS_D)%.o)

HEAD		:=	so_long.h

HEAD_D		:=	.

CFLAGS		:=	-Wall -Wextra #-Werror

AR			:=	ar rcs

NAME		:=	so_long

all			:	$(NAME)

$(NAME)		:	$(OBJS_D) $(OBJS) libft mlx Makefile
				$(CC) $(OBJS) -Llibftbis -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJS)		:	$(OBJS_D)%.o: $(SRCS_D)%.c $(HEAD)
				$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -Ilibftbis -I$(HEAD_D) -c $< -o $@

$(OBJS_D)	:
				@mkdir -p $(OBJS_D)

mlx			:
				make -C mlx_linux

libft		:
				make -C libftbis

clean		:
				$(RM) -r $(OBJS) $(OBJS_D) $(OBJS_B)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all


.PHONY: all bonus clean fclean re
