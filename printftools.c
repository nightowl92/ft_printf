/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printftools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:16:25 by stherkil          #+#    #+#             */
/*   Updated: 2019/09/12 12:01:17 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ifzero(t_data *arginp, long double inp, long long int inpi)
{
	arginp->nb += ft_putnbrl(inp -
			(long double)inpi >= 0.5 ? inpi + 1 : inpi);
	if (arginp->flagmin)
		arginp->nb += ft_putnchar(' ', arginp->wid -
				arginp->prec - arginp->len - 2 - (arginp->flagplu || inpi < 0));
	return (0);
}

intmax_t		get_signed(va_list valist, t_data *arginp)
{
	intmax_t n;

	if (arginp->lenghh)
		n = ((signed char)va_arg(valist, signed int));
	else if (arginp->lengh)
		n = ((signed short)va_arg(valist, signed int));
	else if (arginp->lengl)
		n = (va_arg(valist, signed long));
	else if (arginp->lengll)
		n = (va_arg(valist, signed long long));
	else
		n = (va_arg(valist, int));
	return (n);
}

uintmax_t		get_unsigned(va_list valist, t_data *arginp)
{
	uintmax_t n;

	if (arginp->lenghh)
		n = ((unsigned char)va_arg(valist, unsigned int));
	else if (arginp->lengh)
		n = ((unsigned short)va_arg(valist, unsigned int));
	else if (arginp->lengl)
		n = (va_arg(valist, unsigned long));
	else if (arginp->lengll)
		n = (va_arg(valist, unsigned long long));
	else
		n = (va_arg(valist, unsigned int));
	return (n);
}
