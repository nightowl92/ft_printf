/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:15:47 by stherkil          #+#    #+#             */
/*   Updated: 2019/09/13 14:26:58 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			getwidt(va_list valist, t_data *arginp, char *s)
{
	int i;

	i = 1;
	if (*s == '*')
	{
		arginp->wid = va_arg(valist, int);
		arginp->iswid = 1;
	}
	else if (ft_isdigit(*s))
	{
		arginp->wid = ft_atoi(s);
		i = ft_numlen(arginp->wid, 10);
		arginp->iswid = 1;
	}
	else
		i = 0;
	return (i);
}

static void	minit(t_data *arginp)
{
	arginp->flagmin = 1;
	arginp->ferr = 1;
	arginp->prec = 0;
}

int			getprec(va_list valist, t_data *arginp, char *s, int i)
{
	if (s[0] != '.')
		return (0);
	arginp->isprec = 1;
	if (s[1] == '*')
		arginp->prec = va_arg(valist, int);
	else if (ft_isdigit(s[1]) || s[1] == '+')
	{
		arginp->prec = ft_atoi(s + 1);
		i = ft_numlen(arginp->prec, 10) + 1;
	}
	else if (s[1] == '-')
	{
		arginp->wid = ft_atoi(s + 1) * -1;
		minit(arginp);
		return (ft_numlen(ft_atoi(s + 1), 10) + 1);
	}
	else
	{
		arginp->prec = 0;
		i = 1;
	}
	arginp->flagzer = 0;
	return (i);
}

int			getleng(t_data *arginp, char *s)
{
	if (s[0] == 'h' && s[1] == 'h')
	{
		arginp->lenghh = 1;
		return (2);
	}
	else if (*s == 'h')
		arginp->lengh = 1;
	else if (*s == 'l' && *(s + 1) == 'l')
	{
		arginp->lengll = 1;
		return (2);
	}
	else if (*s == 'l')
		arginp->lengl = 1;
	else if (*s == 'L')
		arginp->lengbigl = 1;
	else
		return (0);
	return (1);
}
