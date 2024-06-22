# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hzakharc <hzakharc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 19:50:36 by hzakharc          #+#    #+#              #
#    Updated: 2024/06/20 19:05:59 by hzakharc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	src/ft_printf.c
LIBFTDIR	= 	libft/

LIBFTOBJS	= 	libft.a
OBJS		= 	$(SRCS:.c=.o)

CC			= 	cc
RM			= 	rm -f
CCFLAGS		= 	-Wall -Werror -Wextra -I.

NAME		= 	libftprintf.a

all:			libft_build $(NAME)

$(NAME):		$(OBJS)
				cp $(LIBFTDIR)$(LIBFTOBJS) $(NAME)
				ar rcs $(NAME) $(OBJS)

libft_build:
				$(MAKE) -C $(LIBFTDIR)

clean:
				$(RM) $(OBJS)
				cd $(LIBFTDIR) && $(MAKE) clean

fclean:			clean
				$(RM) $(NAME)
				cd $(LIBFTDIR) && $(MAKE) fclean

re:				fclean all

.PHONY:			all clean fclean re $(LIBFTDIR)