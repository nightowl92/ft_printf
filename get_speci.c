/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_speci.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:15:30 by stherkil          #+#    #+#             */
/*   Updated: 2019/09/13 13:59:41 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			applyhash(t_data *arginp)
{
	if (!arginp->flagmin)
	{
		if (arginp->flagzer)
			arginp->nb += ft_putnchar('0', arginp->wid - 1);
		else
			arginp->nb += ft_putnchar(' ', arginp->wid - 1);
	}
	arginp->nb += ft_putnchar('%', 1);
	if (arginp->flagmin)
		arginp->nb += ft_putnchar(' ', arginp->wid - 1);
}

static void			applydi(t_data *arginp, intmax_t inp)
{
	if (arginp->flagzer_)
		arginp->flagzer = 0;
	if (!(!arginp->flaghas && inp == 0 && arginp->prec == 0)
			|| arginp->isprec == 0)
		arginp->canprint = 1;
	arginp->totallen = arginp->wid - ft_max(arginp->prec + (inp < 0),
	arginp->canprint * ft_numlen(inp, 10)) - ((arginp->flagplu && inp >= 0));
	if (arginp->flagsp && (arginp->wid > ft_numlen(inp, 10) ||
				!arginp->iswid) && inp >= 0 && !arginp->flagplu)
		arginp->nb += ft_putnchar(' ', 1);
	if (!arginp->flagmin && !arginp->flagzer)
		arginp->nb += ft_putnchar(' ', arginp->totallen - arginp->flagsp);
	if (arginp->flagplu && inp >= 0)
		arginp->nb += ft_putnchar('+', 1);
	if (inp < 0 && (unsigned long long)inp != -9223372036854775808uL)
		arginp->nb += ft_putnchar('-', 1);
	if (!arginp->flagmin && arginp->flagzer)
		arginp->nb += ft_putnchar('0', arginp->totallen - arginp->flagsp);
	arginp->nb += ft_putnchar('0',
			arginp->prec - ft_numlen(inp, 10) + (inp < 0));
	if (arginp->canprint)
		arginp->nb += ft_putnbrl(ft_abs(inp));
	if (arginp->flagmin)
		arginp->nb += ft_putnchar(' ', arginp->wid - ft_max(arginp->prec,
					ft_numlen(inp, 10)) - (arginp->flagplu && inp >= 0));
}

static void			applyuo(t_data *arginp, int base, uintmax_t inp)
{
	if (!(!arginp->flaghas && inp == 0 &&
				arginp->prec == 0) || arginp->isprec == 0)
		arginp->canprint = 1;
	if (!arginp->flagmin && !arginp->flagzer)
		arginp->nb += ft_putnchar(' ', arginp->wid -
				ft_max(arginp->prec, (arginp->canprint || base == 10) *
					ft_numlen(inp, base)) - arginp->flaghas);
	if (arginp->flaghas && inp != 0)
		arginp->nb += ft_putstr("0");
	if (!arginp->flagmin && arginp->flagzer)
		arginp->nb += ft_putnchar('0', arginp->wid - ft_max(arginp->prec,
					(arginp->canprint || base == 10) *
					ft_numlen(inp, base)) - arginp->flaghas);
	arginp->nb += ft_putnchar('0', arginp->prec - ft_numlen(inp, base));
	if (base == 10)
	{
		ft_putnbr(inp);
		arginp->nb += ft_numlen(inp, 10);
	}
	else if (base == 8 && arginp->canprint)
		arginp->nb += ft_putoctl(inp);
	if (arginp->flagmin)
		arginp->nb += ft_putnchar(' ', arginp->wid -
				ft_max(arginp->prec, ft_numlen(inp, base)) - arginp->flaghas);
}

static void			applyxx(t_data *arginp, char c, uintmax_t inp)
{
	if (!(inp == 0 && arginp->prec == 0) || arginp->isprec == 0)
		arginp->canprint = 1;
	if (!arginp->flagmin && !arginp->flagzer)
		arginp->nb += ft_putnchar(' ', arginp->wid -
				ft_max(arginp->prec, arginp->canprint *
					ft_numlen(inp, 16)) - arginp->flaghas * 2);
	if (c == 'x' && arginp->flaghas && inp != 0)
		arginp->nb += ft_putstr("0x");
	else if (c == 'X' && arginp->flaghas && inp != 0)
		arginp->nb += ft_putstr("0X");
	if (!arginp->flagmin && arginp->flagzer)
		arginp->nb += ft_putnchar('0', arginp->wid -
				ft_max(arginp->prec, arginp->canprint *
					ft_numlen(inp, 16)) - arginp->flaghas *
				2 - arginp->flagsp);
	arginp->nb += ft_putnchar('0', arginp->prec - ft_numlen(inp, 16));
	if (c == 'x' && arginp->canprint)
		arginp->nb += ft_puthex(inp);
	else if (c == 'X' && arginp->canprint)
		arginp->nb += ft_puthexu(inp);
	if (arginp->flagmin)
		arginp->nb += ft_putnchar(' ', arginp->wid
				- ft_max(arginp->prec, ft_numlen(inp, 16))
				- arginp->flaghas * 2);
}

int					getspeci(va_list valist, t_data *arginp, char *s)
{
	int i;
	int base;

	i = 1;
	if (*s == 'u')
		base = 10;
	else if (*s == 'o')
		base = 8;
	if (*s == '%')
		applyhash(arginp);
	else if (*s == 'd' || *s == 'i')
		applydi(arginp, get_signed(valist, arginp));
	else if (*s == 'u' || *s == 'o')
		applyuo(arginp, base, get_unsigned(valist, arginp));
	else if (*s == 'x' || *s == 'X')
		applyxx(arginp, *s, get_unsigned(valist, arginp));
	else if (*s == 'f')
		applyf(valist, arginp, 0.0, 0);
	else if (*s == 'c' || *s == 's' || *s == 'p')
		applycps(valist, *s, arginp, 0);
	else
		i = 0;
	return (i);
}
