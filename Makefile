# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsidney <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/18 22:46:31 by tsidney           #+#    #+#              #
#    Updated: 2021/01/18 23:14:55 by tsidney          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	%_norme/percent_source.c\
					c_norme/char_source.c\
					di_norme/di_minus.c di_norme/di_no_minus.c di_norme/di_source.c\
					di_norme/di_useful_func.c\
					p_norme/minus.c p_norme/n_minus.c p_norme/p_source.c\
					p_norme/starter.c p_norme/useful_funcs.c\
					printf/callers_1.c printf/callers_2.c printf/default_printf_funcs.c\
					printf/printf_source.c printf/processors.c printf/useful_funcs.c\
					s_norme/precision.c s_norme/s_source.c s_norme/useful_funcs.c\
					u_norme/u_source.c u_norme/useful_func.c u_norme/with_minus.c u_norme/without_minus.c\
					xx_norme/no_minus.c xx_norme/precision_funcs.c xx_norme/useful_funcs.c xx_norme/w_minus.c xx_norme/xx_source.c\

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
