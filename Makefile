# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/04 16:17:22 by stherkil          #+#    #+#              #
#    Updated: 2019/09/02 19:30:47 by stherkil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM = /bin/rm -f

NAME = libftprintf.a
SRCS_DIR = ./
FILES = ft_printf \
		get_speci \
		getopts \
		printftools \
		apply_cpsf
		
CFILES = $(patsubst %, $(SRCS_DIR)%.c, $(FILES))
OFILES = $(patsubst %, %.o, $(FILES))
INCLUDES = ./includes
CFLAGS = -Wall -Wextra -Werror -O2

#libft
LIBFT = ./libft/
LIBFT_FILES = ft_isdigit ft_strlen ft_max ft_numlen ft_atoi ft_putchar ft_puthex ft_puthexu ft_putnbr ft_putoct ft_putstr ft_putnbr_fd ft_putstr_fd ft_putchar_fd ft_strdup ft_strcpy ft_memcpy ft_min ft_putnchar ft_abs ft_putnbrl ft_putoctl ft_puthexl ft_puthexul
LIBFT_CFILES = $(patsubst %, $(LIBFT)%.c, $(LIBFT_FILES))
LIBFT_OFILES = $(patsubst %, %.o, $(LIBFT_FILES))
LIBFT_LIB = $(addprefix $(LIBFT), ft.a)
LIBFT_INC = -I $(LIBFT)includes/

all : $(LIBFT_LIB) $(NAME)

$(LIBFT_LIB):
		make -C $(LIBFT)

$(OFILES) :
		gcc $(CFLAGS) -c -I $(INCLUDES) $(LIBFT_INC) $(LIBFT_CFILES) $(CFILES)

$(NAME) : $(OFILES)
		ar rc $(NAME) $(OFILES) $(LIBFT_OFILES)
			ranlib $(NAME)

clean :
		make -C $(LIBFT) clean
			$(RM) $(OFILES)
				$(RM) $(LIBFT_OFILES)

fclean : clean
		make -C $(LIBFT) fclean
			$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
