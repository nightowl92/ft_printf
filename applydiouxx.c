/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applydiouxx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:15:03 by stherkil          #+#    #+#             */
/*   Updated: 2019/08/04 15:59:12 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			putwidth(t_data *arginp, int maxval, int where)
{
	if (where == 0)
	{
		while (arginp->wid > maxval && arginp->flagmin == 0)
		{
			if (arginp->flagzer && !arginp->flagsp)
				ft_putchar('0');
			else
				ft_putchar(' ');
			--(arginp->wid);
		}
	}
	else
	{
		while (arginp->wid > maxval && arginp->flagmin == 1)
		{
			ft_putchar(' ');
			--arginp->wid;
		}
	}
}

void			applydi(va_list valist, t_data *arginp)
{
	long long int	inp;
	int				maxval;

	if (arginp->lengl == 1)
		inp = (long long int)va_arg(valist, long int);
	else if (arginp->lengll == 1)
		inp = va_arg(valist, long long int);
	else
		inp = (long long int)va_arg(valist, int);
	maxval = ft_max(ft_numlen(inp, 10), arginp->prec) + arginp->flagplu;
	putwidth(arginp, maxval, 0);
	if (inp > 0 && arginp->flagplu == 1)
		ft_putchar('+');
	else if (inp > 0 && arginp->flagsp)
		ft_putchar(' ');
	while (arginp->prec > ft_numlen(inp, 10))
	{
		ft_putchar('0');
		--arginp->prec;
	}
	ft_putnbr(inp);
	putwidth(arginp, maxval, 1);
}

static void		ft_putnbrtwo(t_data *arginp,
		unsigned long long int inp, char c, int base)
{
	if (c == 'X')
	{
		if (arginp->flaghas)
			ft_putstr("0X");
		while (arginp->prec > ft_numlen(inp, base))
		{
			ft_putchar('0');
			--arginp->prec;
		}
		ft_puthexu(inp);
	}
	else if (c == 'o')
	{
		if (arginp->flaghas && arginp->prec <= ft_numlen(inp, base))
			ft_putstr("0");
		while (arginp->prec > ft_numlen(inp, base))
		{
			ft_putchar('0');
			--arginp->prec;
		}
		ft_putoct(inp);
	}
}

static void		ft_putnbruoxx(t_data *arginp,
		unsigned long long int inp, char c, int base)
{
	if (c == 'u')
	{
		while (arginp->prec > ft_numlen(inp, base))
		{
			ft_putchar('0');
			--arginp->prec;
		}
		ft_putnbr(inp);
	}
	else if (c == 'x')
	{
		if (arginp->flaghas)
			ft_putstr("0x");
		while (arginp->prec > ft_numlen(inp, base))
		{
			ft_putchar('0');
			--arginp->prec;
		}
		ft_puthex(inp);
	}
	else if (c == 'X' || c == 'o')
		ft_putnbrtwo(arginp, inp, c, base);
}

void			applyuoxx(va_list valist, t_data *arginp, char c)
{
	unsigned long long int	inp;
	int						base;
	int						maxval;

	if (arginp->lengl == 1)
		inp = (unsigned long long int)va_arg(valist, unsigned long int);
	else if (arginp->lengll == 1)
		inp = va_arg(valist, unsigned long long int);
	else
		inp = (unsigned long long int)va_arg(valist, unsigned int);
	base = (c == 'o' ? 8 : 16);
	base = (c == 'u' ? 10 : base);
	maxval = ft_max(ft_numlen(inp, base), arginp->prec) + arginp->flagplu;
	putwidth(arginp, ft_max(ft_numlen(inp, base),
				arginp->prec) + arginp->flagplu, 0);
	ft_putnbruoxx(arginp, inp, c, base);
	putwidth(arginp, maxval, 1);
}
