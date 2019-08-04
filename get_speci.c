/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_speci.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:15:30 by stherkil          #+#    #+#             */
/*   Updated: 2019/08/04 16:23:28 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		applyftwo(t_data *arginp,
	long double inp, int mult, int maxval)
{
	if (arginp->flagplu && inp > 0.0)
		ft_putchar('+');
	else if ((int)inp > 0 && arginp->flagsp)
		ft_putchar(' ');
	ft_putnbr((int)inp);
	ft_putchar('.');
	inp = inp - (int)inp;
	if (inp < 0.0)
		inp = -inp;
	while (mult)
	{
		inp *= 10;
		ft_putnbr((int)inp);
		inp = inp - (int)inp;
		--mult;
	}
	putwidth(arginp, maxval, 1);
}

static void		applyf(va_list valist, t_data *arginp)
{
	long double		inp;
	long long int	inpi;
	int				mult;
	int				maxval;

	mult = 1;
	if (arginp->lengL)
		inp = va_arg(valist, long double);
	else
		inp = (long double)va_arg(valist, double);
	inpi = (long long int)inp;
	if (arginp->ferr)
	{
		ft_putnbr(inpi);
		putwidth(arginp, ft_numlen(inpi, 10), 1);
		return ;
	}
	if (arginp->prec == -1)
		mult = 6;
	else
		mult = arginp->prec;
	maxval = mult + 1 + ft_numlen(inpi, 10);
	putwidth(arginp, maxval, 0);
	applyftwo(arginp, inp, mult, maxval);
}

static void		applycps(va_list valist, char c)
{
	uintmax_t	inp;

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

int				getspeci(va_list valist, t_data *arginp, char *s)
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
		applycps(valist, *s);
	else
		i = 0;
	return (i);
}
