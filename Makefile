# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 16:45:45 by grebrune          #+#    #+#              #
#    Updated: 2024/02/01 20:14:00 by grebrune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########################################################################################################################
#                                                       VARIABLE                                                       #
########################################################################################################################

SRCS		:=	so_long.c\
				parsing.c\
				parsing_utils.c\
				print_map.c\
				close_win.c\
				game_move.c\
				tab_creator.c\

SRCS_B		:=	so_long.c\
				parsing_bonus.c\
				parsing_utils.c\
				print_map.c\
				close_win.c\
				game_move.c\
				tab_creator.c\

SRCS_D		:=	src/

OBJS_D		:=	objs/

OBJS_B_D	:=	objs_b/

OBJS		:=	$(SRCS:%.c=$(OBJS_D)%.o)

OBJS_B		:=	$(SRCS_B:%.c=$(OBJS_B_D)%.o)

HEAD		:=	so_long.h

HEAD_D		:=	.

CFLAGS		:=	-Wall -Wextra -Werror

NAME		:=	so_long

NAME_B		:=	so_long_bonus

########################################################################################################################
#                                                         LIB                                                          #
########################################################################################################################
LIB			:=	libft.a

LIB_D		:=	libftbis/

LIB_I		:=	$(LIB_D)

LIB_H		:=	$(LIB_I)libft.h

LIB_A		:=	$(LIB_D)$(LIB)

MLX			:=	libmlx.a

MLX_D		:=	mlx_linux/

MLX_F		:=	-L$(MLX_D) -L/usr/lib -lmlx -lXext -lX11 -lm -lz

MLX_H		:=	$(MLX_D)mlx.h

MLX_A		:=	$(MLX_D)$(MLX)

########################################################################################################################
#                                                        RULES                                                         #
########################################################################################################################

$(NAME)		:	$(OBJS_D) $(OBJS) $(LIB_A) $(MLX_A) $(LIB_H) $(MLX_H) $(HEAD)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_A) $(LIB_A) $(MLX_F)

$(OBJS)		:	$(OBJS_D)%.o: $(SRCS_D)%.c $(HEAD) $(LIB_H) $(MLX_H)
				$(CC) $(CFLAGS) -I/usr/include -Ilibftbis -Imlx_linux -c $< -o $@

$(OBJS_D)	:
				@mkdir -p $(OBJS_D)

$(LIB_A)	:	$(LIB_D) $(LIB_H)
				$(MAKE) -C $(LIB_D)

$(MLX_A)	:	$(MLX_D) $(MLX_H)
				$(MAKE) -j -C $(MLX_D) 2>/dev/null

########################################################################################################################
#                                                        BONUS                                                         #
########################################################################################################################

$(NAME_B)	:	 $(OBJS_B_D) $(OBJS_B) $(LIB_A) $(MLX_A)
				$(CC) $(CFLAGS) -o $(NAME_B) $(OBJS_B) $(MLX_A) $(LIB_A) $(MLX_F)

$(OBJS_B)	:	$(OBJS_B_D)%.o: $(SRCS_D)%.c $(HEAD)
				$(CC) $(CFLAGS) -I/usr/include -I$(LIB_I) -I$(MLX_I) -c $< -o $@

$(OBJS_B_D)	:
				@mkdir -p $(OBJS_B_D)


########################################################################################################################
#                                                        COMMANDS                                                      #
########################################################################################################################

all			:	$(NAME)

bonus		:	$(NAME_B)

clean		:
				$(RM) -r $(OBJS) $(OBJS_D) $(OBJS_B) $(OBJS_B_D)
				make clean -C libftbis
				make clean -C mlx_linux

fclean		:	clean
				$(RM) $(NAME) $(NAME_B)
				make fclean -C libftbis
				make clean -C mlx_linux

re			:	fclean all


.PHONY: all bonus clean fclean re
