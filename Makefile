

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

BNS			=	$(shell ./so_long_bonus maps/map_l.ber)

RUN			=	$(shell ./so_long maps/no_fun.ber)

########################################################################################################################
#                                                         LIB                                                          #
########################################################################################################################
LIB			:=	libft.a

LIB_D		:=	libftbis/

LIB_I		:=	$(LIB_D)

LIB_H		:=	$(LIB_I)libft.h

LIB_A		:=	$(addprefix $(LIB_D), $(LIB))

MLX			:=	libmlx.a

MLX_D		:=	mlx_linux/

MLX_F		:=	-L$(MLX_D) -L/usr/lib -lmlx -lXext -lX11 -lm -lz

MLX_H		:=	$(MLX_D)mlx.h

MLX_A		:=	$(addprefix $(MLX_D), $(MLX))

PRI			:=	libftprintf.a

PRI_D		:=	ft_printf/

PRI_H		:=	$(PRI_D)ft_printf.h

PRI_A		:=	$(addprefix $(PRI_D), $(PRI))

########################################################################################################################
#                                                        RULES                                                         #
########################################################################################################################

all			:	lib
				$(MAKE) --silent $(NAME)

bonus		:	lib
				$(MAKE) --silent $(NAME_B)

run			:	all
				@echo $(RUN)

full		:	bonus
				@echo $(BNS)

lib			:
				$(MAKE) --silent -C $(LIB_D)
				$(MAKE) --silent -C $(PRI_D)
				$(MAKE) --silent -C $(MLX_D) 2>/dev/null

$(NAME)		:	$(OBJS_D) $(OBJS) $(LIB_A) $(MLX_A) $(PRI_A) $(HEAD)
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_A) $(LIB_A) $(PRI_A) $(MLX_F)

$(OBJS)		:	$(OBJS_D)%.o: $(SRCS_D)%.c $(HEAD) $(MLX_H) $(LIB_H) $(PRI_H) Makefile
				@$(CC) $(CFLAGS) -I/usr/include -Ilibftbis -Imlx_linux -c $< -o $@

$(OBJS_D)	:
				@mkdir -p $(OBJS_D)


########################################################################################################################
#                                                        BONUS                                                         #
########################################################################################################################

$(NAME_B)	:	 $(OBJS_B_D) $(OBJS_B) $(LIB_A) $(MLX_A) $(PRI_A) $(HEAD)
				$(CC) $(CFLAGS) -o $(NAME_B) $(OBJS_B) $(MLX_A) $(LIB_A) $(MLX_F) $(PRI_A)

$(OBJS_B)	:	$(OBJS_B_D)%.o: $(SRCS_D)%.c $(HEAD) $(LIB_H) $(MLX_H) $(PRI_H) Makefile
				$(CC) $(CFLAGS) -I/usr/include -Ilibftbis -Imlx_linux -c $< -o $@

$(OBJS_B_D)	:
				mkdir -p $(OBJS_B_D)

########################################################################################################################
#                                                        COMMANDS                                                      #
########################################################################################################################

clean		:
				$(RM) -r $(OBJS) $(OBJS_D) $(OBJS_B) $(OBJS_B_D)
				$(MAKE) --silent clean -C libftbis
				$(MAKE) --silent clean -C mlx_linux
				$(MAKE) --silent clean -C ft_printf

fclean		:	clean
				$(RM) $(NAME) $(NAME_B)
				$(MAKE) --silent fclean -C libftbis
				$(MAKE) --silent fclean -C ft_printf

re			:	fclean all

.PHONY: all bonus clean fclean re lib run full
.SILENT: all bonus clean fclean re lib
