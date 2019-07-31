/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 16:40:39 by stherkil          #+#    #+#             */
/*   Updated: 2019/07/31 17:55:45 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		init(t_data *arginp)
{
	arginp->flagno = 0;
	arginp->flagmin = 0;
	arginp->flagplu = 0;
	arginp->flagsp = 0;
	arginp->flaghas = 0;
	arginp->flagzer = 0;
	arginp->wid = 0;
	arginp->prec = 0;
	arginp->lengno = 0;
	arginp->lenghh = 0;
	arginp->lengh = 0;
	arginp->lengl = 0;
	arginp->lengll = 0;
	arginp->lengL = 0;
}

int			getflag(t_data *arginp, char *s)
{
	int i;

	i = 1;
	if (s[0] == '-')
		arginp->flagmin = 1;
	else if (s[0] == '+')
		arginp->flagplu = 1;
	else if (s[0] == ' ')
	{
		if (!arginp->flagzer)
			arginp->flagsp = 1;
	}
	else if (s[0] == '#')
		arginp->flaghas = 1;
	else if (s[0] == '0')
		arginp->flagzer = 1;
	else
	{
		arginp->flagno = 1;
		i = 0;
	}
	return (i);
}

int			getwidt(va_list valist, t_data *arginp, char *s)
{
	int i;

	i = 1;
	if (*s == '*')
		arginp->wid = va_arg(valist, int);
	else if (ft_isdigit(*s))
	{
		arginp->wid = ft_atoi(s);
		i = ft_numlen(arginp->wid, 10);
	}
	else
		i = 0;
	return (i);
}

int			getprec(va_list valist, t_data *arginp, char *s)
{
	int i;

	i = 1;
	if (*s == '*')
		arginp->prec = va_arg(valist, int);
	else if (ft_isdigit(*s))
	{
		arginp->prec = ft_atoi(s);
		i = ft_numlen(arginp->wid, 10);
	}
	else
		i = 0;
	if (arginp->prec)
		arginp->wid = 0;
	return (i);
}

int			getleng(t_data *arginp, char *s)
{
	int i;

	i = 1;
	arginp->lengno = 0;
	if (*s == 'h')
	{
		if (*(s + 1) == 'h')
		{
			i = 2;
			arginp->lenghh = 1;
		}
		else
			arginp->lengh = 1;
	}
	else if (*s == 'l')
	{
		if (*(s + 1) == 'l')
		{
			i = 2;
			arginp->lengll = 1;
		}
		else
			arginp->lengl = 1;
	}
	else if (*s == 'L')
	{
		arginp->lengL = 1;
	}
	else
	{
		i = 0;
		arginp->lengno = 1;
	}
	return (i);
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
	while (arginp->wid + arginp->flagplu > ft_numlen(inp, 10) && arginp->flagmin == 0)
	{
		if (arginp->flagzer && !arginp->flagsp)
			ft_putchar('0');
		else
			ft_putchar(' ');
		--arginp->wid;
	}
	if (inp > 0 && arginp->flagplu == 1)
		ft_putchar('+');
	ft_putnbr(inp);
	while (arginp->wid > ft_numlen(inp, 10) && arginp->flagmin == 1)
	{
		ft_putchar(' ');
		--arginp->wid;
	}
}

void ft_putnbruoxx(unsigned long long int inp, char c)
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
	unsigned long long int inp;
	int base;

	if (arginp->lengno == 1)
		inp = (unsigned long long int)va_arg(valist,unsigned int);
	else if (arginp->lengl == 1)
		inp = (unsigned long long int)va_arg(valist,unsigned long int);
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
	while (arginp->wid + arginp->flagplu && inp > ft_numlen(inp, base) && arginp->flagmin == 0)
	{
		if (arginp->flagzer && !arginp->flagsp)
			ft_putchar('0');
		else
			ft_putchar(' ');
		--arginp->wid;
	}
	if (arginp->flagplu == 1)
		ft_putchar('+');
	if (base == 10)
	ft_putnbruoxx(inp, base);
	while (arginp->wid > ft_numlen(inp, base) && arginp->flagmin == 1)
	{
		ft_putchar(' ');
		--arginp->wid;
	}
}

void		applyf(va_list valist, t_data *arginp)
{
	if (arginp->flagno == 1)
		va_arg(valist, int);
}

void		applycps(va_list valist, t_data *arginp, char c)
{
	if (c == 's')
		ft_putstr(va_arg(valist, char*));
	else if (c == 'c')
		ft_putchar(va_arg(valist, int));
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

int			getargs(va_list valist, t_data *arginp, char *s, int *nb)
{
	int i;
	int ii;

	i = 0;
	if (s[0] == '%')
	{
		ft_putchar('%');
		return (1);
	}
	init(arginp);
	while ((ii = getflag(arginp, s + i)))
		i += ii;
	i += getwidt(valist, arginp, s + i);
	i += getprec(valist, arginp, s + i);
	i += getleng(arginp, s + i);
	i += getspeci(valist, arginp, s + i);
	return (i);
}

int			ft_printf(char *s, ...)
{
	t_data	*arginp;
	va_list	valist;
	int		i;
	int		nb;

	i = -1;
	nb = 0;
	va_start(valist, s);
	if (!(arginp = (t_data*)malloc(sizeof(t_data))))
		return (0);
	while (s[++i])
	{
		if (s[i] == '%')
			i += getargs(valist, arginp, s + i + 1, &nb);
		else
		{
			write(1, s + i, 1);
			++nb;
		}
	}
	va_end(valist);
	return (nb);
}
