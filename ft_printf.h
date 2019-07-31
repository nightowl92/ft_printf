/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 16:40:47 by stherkil          #+#    #+#             */
/*   Updated: 2019/07/31 18:13:34 by stherkil         ###   ########.fr       */
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
	int flagno;
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
	int lengL;
	int lengll;
}					t_data;
int			getwidt(va_list valist, t_data *arginp, char *s);
int			getprec(va_list valist, t_data *arginp, char *s);
int			getleng(t_data *arginp, char *s);
int			getspeci(va_list valist, t_data *arginp, char *s);
void		applyuoxx(va_list valist, t_data *arginp, char c);
void		applydi(va_list valist, t_data *arginp);
#endif
