/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applydiouxx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:15:03 by stherkil          #+#    #+#             */
/*   Updated: 2019/08/02 16:49:31 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_max(int a, int b)
{
	return (a > b ? a : b);
}

void		applydi(va_list valist, t_data *arginp)
{
	long long int inp;

	if (arginp->lengno == 1)
		inp = (long long int)va_arg(valist, int);
	else if (arginp->lengl == 1)
		inp = (long long int)va_arg(valist, long int);
	else if (arginp->lengll == 1)
		inp = va_arg(valist, long long int);
	else
		inp = (long long int)va_arg(valist, int);
	while (arginp->wid - arginp->flagplu > ft_max(ft_numlen(inp, 10), arginp->prec) && arginp->flagmin == 0)
	{
		if (arginp->flagzer && !arginp->flagsp)
			ft_putchar('0');
		else
			ft_putchar(' ');
		--(arginp->wid);
	}
	if (inp > 0 && arginp->flagplu == 1)
		ft_putchar('+');
	while (arginp->prec > ft_numlen(inp, 10))
	{
		ft_putchar('0');
		--arginp->prec;
	}
	ft_putnbr(inp);
	while (arginp->wid > ft_numlen(inp, 10) && arginp->flagmin == 1)
	{
		ft_putchar(' ');
		--arginp->wid;
	}
}

void		ft_putnbruoxx(unsigned long long int inp, char c)
{
	if (c == 'u')
		ft_putnbr(inp);
	else if (c == 'x')
		ft_puthex(inp);
	else if (c == 'X')
		ft_puthexu(inp);
	else if (c == 'o')
		ft_putoct(inp);
}

void		applyuoxx(va_list valist, t_data *arginp, char c)
{
	unsigned long long int	inp;
	int						base;

	if (arginp->lengno == 1)
		inp = (unsigned long long int)va_arg(valist, unsigned int);
	else if (arginp->lengl == 1)
		inp = (unsigned long long int)va_arg(valist, unsigned long int);
	else if (arginp->lengll == 1)
		inp = va_arg(valist, unsigned long long int);
	else
		inp = (unsigned long long int)va_arg(valist, int);
	if (c == 'u')
		base = 10;
	else if (c == 'o')
		base = 8;
	else
		base = 16;
	while (arginp->wid > ft_max(ft_numlen(inp, base), arginp->prec) && arginp->flagmin == 0)
	{
		if (arginp->flagzer && !arginp->flagsp)
			ft_putchar('0');
		else
			ft_putchar(' ');
		--(arginp->wid);
	}
	while (arginp->prec > ft_numlen(inp, base))
	{
		ft_putchar('0');
		--arginp->prec;
	}
	ft_putnbruoxx(inp, c);
	while (arginp->wid > ft_numlen(inp, base) && arginp->flagmin == 1)
	{
		ft_putchar(' ');
		--(arginp->wid);
	}
}
