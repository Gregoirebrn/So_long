# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 16:45:45 by grebrune          #+#    #+#              #
#    Updated: 2023/12/15 16:31:19 by grebrune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		:= so_long.c

SRCS_D		:=	#

OBJS_D		:=	objs/

OBJS		:=	$(SRCS:%.c=$(OBJS_D)%.o)

HEAD_D		:=	.

CFLAGS		:=	-Wall -Wextra #-Werror

AR			:=	ar rcs

NAME		:=	so_long

all			:	$(NAME)

$(NAME)		:	$(OBJS_D) $(OBJS) libft mlx Makefile
				$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJS)		:	$(OBJS_D)%.o: $(SRCS_D)%.c $(HEAD)
				$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -Ilibftbis -O3 -c $< -o $@

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
