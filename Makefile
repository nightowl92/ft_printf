# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stherkil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/04 16:17:22 by stherkil          #+#    #+#              #
#    Updated: 2019/08/04 16:30:18 by stherkil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM = /bin/rm -f

NAME = libftprintf.a
SRCS_DIR = ./
FILES = ft_printf \
		applydiouxx \
		get_speci \
		getopts \
		
CFILES = $(patsubst %, $(SRCS_DIR)%.c, $(FILES))
OFILES = $(patsubst %, %.o, $(FILES))
INCLUDES = ./includes
CFLAGS = -Wall -Wextra -Werror -O2

#libft
LFT = ./libft/
LFT_FILES = ft_isdigit ft_strlen ft_max ft_numlen ft_atoi ft_putchar ft_puthex ft_puthexu ft_putnbr ft_putoct ft_putstr ft_putnbr_fd ft_putstr_fd ft_putchar_fd
LFT_CFILES = $(patsubst %, $(LFT)%.c, $(LFT_FILES))
LFT_OFILES = $(patsubst %, %.o, $(LFT_FILES))
LFT_LIB = $(addprefix $(LFT), ft.a)
LFT_INC = -I $(LFT)includes/


.PHONY: all clean fclean re

all : $(LFT_LIB) $(NAME)

$(LFT_LIB):
		make -C $(LFT)

$(OFILES) :
		gcc $(CFLAGS) -c -I $(INCLUDES) $(LFT_INC) $(LFT_CFILES) $(CFILES)

$(NAME) : $(OFILES)
		ar rc $(NAME) $(OFILES) $(LFT_OFILES)
			ranlib $(NAME)

clean :
		make -C $(LFT) clean
			$(RM) $(OFILES)
				$(RM) $(LFT_OFILES)

fclean : clean
		make -C $(LFT) fclean
			$(RM) $(NAME)

re : fclean all
