/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 16:40:47 by stherkil          #+#    #+#             */
/*   Updated: 2019/07/29 15:33:38 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
#define PRINTF_H
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "./libft/libft.h"

int		ft_printf(char *s, ...);

typedef struct		s_data
{
	int flagmin;
	int flagplu;
	int flagsp;
	int flaghas;
	int flagzer;

	int wid;

	int prec;

	int lengno;
	int lenghh;
	int lengh;
	int lengl;
	int lengll;
	int lengj;
	int lengz;
	int lengt;
	int lengL;
}					t_data;


#endif
