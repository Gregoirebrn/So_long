# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 16:45:45 by grebrune          #+#    #+#              #
#    Updated: 2023/11/30 15:41:42 by grebrune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		:=	ft_printf.c\
				ft_printf_utils.c\
				ft_putnbr_base.c\

SRCS_D		:=	src/

OBJS_D		:=	objs/

OBJS		:=	$(SRCS:%.c=$(OBJS_D)%.o)

HEAD		:=	ft_printf.h

HEAD_D		:=	.

CFLAGS		:=	-Wall -Wextra -Werror

CC			:=	cc

AR			:=	ar -rcs

NAME		:=	libftprintf.a

all			:	$(NAME)

$(NAME)		:	$(OBJS_D) $(OBJS) Makefile
				$(AR) -o $(NAME) $(OBJS)

$(OBJS)		:	$(OBJS_D)%.o: $(SRCS_D)%.c $(HEAD) #$(SRCS)
				$(CC) $(CFLAGS) -I$(HEAD_D) -c $< -o $@

$(OBJS_D)	:
				@mkdir -p $(OBJS_D)

clean		:
				$(RM) -r $(OBJS) $(OBJS_D)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all


.PHONY: all bonus clean fclean re
