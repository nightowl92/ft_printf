/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 16:40:39 by stherkil          #+#    #+#             */
/*   Updated: 2019/07/29 15:49:03 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_numlen(int nb)
{
	int i;

	i = 0;
	while ((nb /= 10))
		++i;
	return (i);
}

void init(t_data *arginp)
{
	arginp->flagmin = 0;
	arginp->flagplu = 0;
	arginp->flagsp = 0;
	arginp->flaghas = 0;
	arginp->flagzer = 0;

	arginp->wid = -1;

	arginp->prec = -1;

	arginp->lengno = 0;
	arginp->lenghh = 0;
	arginp->lengh = 0;
	arginp->lengl = 0;
	arginp->lengll = 0;
	arginp->lengj = 0;
	arginp->lengz = 0;
	arginp->lengt = 0;
	arginp->lengL = 0;
}

int		getflag(t_data *arginp, char *s)
{
	int i;

	i = 1;
	if (s[i] == '-')
		arginp->flagmin = 1;
	else if (s[i] == '+')
		arginp->flagplu = 1;
	else if (s[i] == ' ')
		arginp->flagsp = 1;
	else if (s[i] == '#')
		arginp->flaghas = 1;
	else if (s[i] == '0')
		arginp->flagzer = 1;
	else
		i = 0;
	return (i);
}

int		getwidt(va_list valist, t_data *arginp, char *s)
{
	int i;

	i = 1;
	if (*s == '*')
		arginp->wid = va_arg(valist, int);
	else if (ft_isdigit(*s))
	{
		arginp->wid = ft_atoi(s);
		i = ft_numlen(arginp->wid);
	}
	else
		i = 0;
	return (i);
}

int		getprec(va_list valist, t_data *arginp, char *s)
{
	int i;

	i = 1;
	if (*s == '*')
		arginp->prec = va_arg(valist, int);
	else if (ft_isdigit(*s))
	{
		arginp->prec = ft_atoi(s);
		i = ft_numlen(arginp->wid);
	}
	else
		i = 0;
	return (i);
}

int		getleng(t_data *arginp, char *s)
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
	else if (*s == 'j')
	{
		arginp->lengj = 1;
	}
	else if (*s == 'z')
	{
		arginp->lengz = 1;
	}
	else if (*s == 't')
	{
		arginp->lengt = 1;
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

void applydi()
{
	
}

void applyuoxx()
{
	
}

void applyffeeggaa()
{
	
}

void applyc()
{
	
}

void applys()
{
	
}

void applyp()
{
	
}

void applyn()
{
	
}

int		getspeci(va_list valist, t_data *arginp, char *s)
{
	if (*s == 'd' || *s == 'i')
		applydi();
	else if (*s == 'u' || *s == 'o' || *s == 'x' || *s == 'X')
		applyuoxx();
	else if (*s == 'f' || *s == 'F' || *s == 'e' || *s == 'E' || *s == 'g' || *s == 'G' || *s == 'a' || *s == 'A')
		applyffeeggaa();
	else if (*s == 'c')
		applyc();
	else if (*s == 's')
		applys();
	else if (*s == 'p')
		applyp();
	else if (*s == 'n')
		applyn();
	return (1);
}

int		getargs(va_list valist, t_data *arginp, char *s, int *nb)
{
	int i;

	i = 1;
	if (s[0] == '%')
	{
		ft_putchar('%');
		return (1);
	}
	init(arginp);
	i += getflag(arginp, s + i);
	i += getwidt(valist, arginp, s + i);
	i += getprec(valist, arginp, s + i);
	i += getleng(arginp, s + i);
	i += getspeci(valist, arginp, s + i);
	return (i);
}

int		ft_printf(char *s, ...)
{
	t_data *arginp;
	va_list valist;
	int     i;
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
