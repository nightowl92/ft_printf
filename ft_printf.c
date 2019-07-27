/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 16:40:39 by stherkil          #+#    #+#             */
/*   Updated: 2019/07/27 18:30:38 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		getfct(va_list valist, char *s, int i)
{
int nb;
    if (s[i] == 'd')
    {
        nb = va_arg(valist, int);
        ft_putstr(ft_itoa(nb));

    }
	return (i);
}

int		ft_printf(char *s, ...)
{
	va_list valist;
	int     i;

	i = -1;
	va_start(valist, s);
	while (s[++i])
	{
		if (s[i] == '%')
			i = getfct(valist, s, i + 1);        
		else
			write(1, s + i, 1);
	}
	va_end(valist);
	return (0);
}
