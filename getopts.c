/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:15:47 by stherkil          #+#    #+#             */
/*   Updated: 2019/07/31 18:15:51 by stherkil         ###   ########.fr       */
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
