/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 16:40:39 by stherkil          #+#    #+#             */
/*   Updated: 2019/08/01 15:00:25 by stherkil         ###   ########.fr       */
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
	arginp->prec = -1;
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
