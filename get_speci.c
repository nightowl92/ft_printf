/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_speci.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:15:30 by stherkil          #+#    #+#             */
/*   Updated: 2019/08/01 15:18:15 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		applyf(va_list valist, t_data *arginp)
{
	double out;
	int mult;

	mult = 1;
		out = va_arg(valist, double);
	ft_putnbr((long long int)out);
	ft_putchar('.');
	out = out - (long)out;
	if (arginp->prec == -1)
		arginp->prec = 6;
	out *= 10;
	ft_putnbr((int)out);
	out = out - (long)out;
	out *= 10;
	ft_putnbr((int)out);
	out = out - (long)out;
	out *= 10;
	ft_putnbr((int)out);
	out = out - (long)out;
	out *= 10;
	ft_putnbr((int)out);
	out = out - (long)out;
	out *= 10;
	ft_putnbr((int)out);
	out = out - (long)out;
	out *= 10;
	ft_putnbr((long long int)out);
}

void		applycps(va_list valist, t_data *arginp, char c)
{
	uintmax_t inp;

	if (c == 's')
		ft_putstr(va_arg(valist, char*));
	else if (c == 'c')
		ft_putchar(va_arg(valist, int));
	else if (c == 'p')
	{
		ft_putstr("0x7fff");
		inp = (long long)va_arg(valist, void *);
		ft_puthex(inp);
	}
}

int			getspeci(va_list valist, t_data *arginp, char *s)
{
	int i;

	i = 1;
	if (*s == 'd' || *s == 'i')
		applydi(valist, arginp);
	else if (*s == 'u' || *s == 'o' || *s == 'x' || *s == 'X')
		applyuoxx(valist, arginp, *s);
	else if (*s == 'f')
		applyf(valist, arginp);
	else if (*s == 'c' || *s == 's' || *s == 'p')
		applycps(valist, arginp, *s);
	else
		i = 0;
	return (i);
}
