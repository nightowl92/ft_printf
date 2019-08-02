/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:15:47 by stherkil          #+#    #+#             */
/*   Updated: 2019/08/02 16:49:59 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

	i = 2;
	if (s[0] != '.')
		return (0);
	if (s[1] == '*')
		arginp->prec = va_arg(valist, int);
	else if (ft_isdigit(s[1]) || s[1] == '+')
	{
		arginp->prec = ft_atoi(s + 1);
		i = ft_numlen(arginp->prec, 10) + 1;
	}
	else if (s[1] == '-')
	{
		arginp->prec = 0;
		i = ft_numlen(ft_atoi(s + 1), 10) + 1;
	}
	else
		i = 1;
	if (arginp->prec != -1 && arginp->wid <= arginp->prec)
		arginp->wid = 0;
	arginp->flagzer = 0;
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
