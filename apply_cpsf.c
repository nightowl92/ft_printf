/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_cpsf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:21:24 by stherkil          #+#    #+#             */
/*   Updated: 2019/09/13 15:27:24 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			applyfend(t_data *arginp,
long double inp, long long int inpi)
{
	arginp->nb += (arginp->len = ft_putnbrl((int)inp));
	arginp->nb += ft_putnchar('.', 1);
	inp = inp - (int)inp;
	if (inp < 0.0)
		inp = -inp;
	while (arginp->prec - 1)
	{
		inp *= 10;
		arginp->nb += ft_putnbrl((int)inp);
		inp = inp - (int)inp;
		--arginp->prec;
	}
	inp *= 10;
	inpi = (long long int)inp;
	arginp->nb += ft_putnbrl((inp - (long double)inpi >= 0.5) &&
			inpi != 9 ? inpi + 1 : inpi);
	if (arginp->flagmin)
		arginp->nb += ft_putnchar(' ', arginp->wid -
				arginp->prec - arginp->len - 2);
	return (0);
}

int					applyf(va_list valist, t_data *arginp,
long double inp, long long int inpi)
{
	if (arginp->lengbigl)
		inp = va_arg(valist, long double);
	else
		inp = (long double)va_arg(valist, double);
	inpi = (long long int)inp;
	arginp->len = ft_numlen(ft_abs(inpi), 10);
	arginp->prec = (arginp->isprec ? arginp->prec : 6);
	if ((((arginp->flagzerf && arginp->iswid) || !arginp->iswid) &&
				(!(arginp->flagplu || inpi < 0))) && arginp->flagsp)
		arginp->nb += ft_putnchar(' ', 1);
	if (!arginp->flagzerf && arginp->iswid)
		arginp->nb += ft_putnchar(' ', arginp->wid -
		(arginp->prec + 1 + arginp->len) - (arginp->flagplu || inpi < 0));
	if (arginp->flagplu && inp >= 0)
		arginp->nb += ft_putnchar('+', 1);
	if (inp < 0 && (unsigned long long)inp != -9223372036854775808uL)
		arginp->nb += ft_putnchar('-', 1);
	if (arginp->flagzerf && arginp->iswid)
		arginp->nb += ft_putnchar('0', arginp->wid -
		(arginp->prec + 1 + arginp->len) - (arginp->flagplu || inpi < 0));
	if (inp < 0)
		inp *= -1;
	if (arginp->isprec && !arginp->prec)
		return (ifzero(arginp, inp, inpi));
	return (applyfend(arginp, inp, inpi));
}

void				applys(va_list valist, t_data *arginp, char *s, int len)
{
	if (!(s = va_arg(valist, char*)))
		s = "(null)";
	len = (arginp->prec < ft_strlen(s)) && arginp->isprec ?
		arginp->prec : ft_strlen(s);
	if (!arginp->flagmin)
	{
		if (arginp->flagzer)
			arginp->nb += ft_putnchar('0', arginp->wid - len);
		else
			arginp->nb += ft_putnchar(' ', arginp->wid - len);
	}
	while (*s)
	{
		if (arginp->isprec && arginp->prec <= 0)
			break ;
		arginp->nb += ft_putnchar(*s, 1);
		arginp->prec -= 1;
		s++;
	}
	if (arginp->flagmin)
		arginp->nb += ft_putnchar(' ', arginp->wid - len);
}

static void			applyp(va_list valist, t_data *arginp, uintmax_t inp)
{
	inp = (long long)va_arg(valist, void *);
	if (!arginp->flagmin)
	{
		if (arginp->flagzer)
			arginp->nb += ft_putnchar('0',
					arginp->wid - 2 - ft_numlen(inp, 16));
		else
			arginp->nb += ft_putnchar(' ',
					arginp->wid - 2 - ft_numlen(inp, 16));
	}
	ft_putstr("0x");
	arginp->nb += ft_puthex(inp) + 2;
	if (arginp->flagmin)
		arginp->nb += ft_putnchar(' ',
				arginp->wid - 2 - ft_numlen(inp, 16));
}

void				applycps(va_list valist, char c, t_data *arginp, int len)
{
	uintmax_t	inp;
	char		ch;
	char		*s;

	s = NULL;
	inp = 0;
	if (c == 's')
		applys(valist, arginp, s, len);
	else if (c == 'c')
	{
		if (!arginp->flagmin)
		{
			if (arginp->flagzer)
				arginp->nb += ft_putnchar('0', arginp->wid - 1);
			else
				arginp->nb += ft_putnchar(' ', arginp->wid - 1);
		}
		ch = va_arg(valist, int);
		arginp->nb += ft_putnchar(ch, 1);
		if (arginp->flagmin)
			arginp->nb += ft_putnchar(' ', arginp->wid - 1);
	}
	else if (c == 'p')
		applyp(valist, arginp, inp);
}
