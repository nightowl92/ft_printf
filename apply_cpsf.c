#include "ft_printf.h"

void		applyf(va_list valist, t_data *arginp)
{
	long double		inp;
	long long int	inpi;
	int				mult;
	int				maxval;

	mult = 1;
	if (arginp->lengbigl)
		inp = va_arg(valist, long double);
	else
		inp = (long double)va_arg(valist, double);
	inpi = (long long int)inp;
	if (arginp->ferr)
	{
		ft_putnbr(inpi);
		return ;
	}
	if (!arginp->isprec)
		mult = 6;
	else
		mult = arginp->prec;
	maxval = mult + 1 + ft_numlen(inpi, 10);
	arginp->nb += maxval;
}

void		applycps(va_list valist, char c, t_data *arginp)
{
    int         len;
	uintmax_t	inp;
	char		*s;
    char        ch;

	if (c == 's')
	{
		if (!(s = va_arg(valist, char*)))
		{
            arginp->nb += ft_printf("(null)");
			return ;
		}
        len = (arginp->prec < ft_strlen(s)) && arginp->isprec ? arginp->prec : ft_strlen(s);
        if (!arginp->flagmin)
            arginp->nb += ft_putnchar(' ', arginp->wid - len);
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
	else if (c == 'c')
	{
        if (!arginp->flagmin)
            arginp->nb += ft_putnchar(' ', arginp->wid - 1);
		ch = va_arg(valist, int);
        arginp->nb += ft_putnchar(ch, 1);
        if (arginp->flagmin)
            arginp->nb += ft_putnchar(' ', arginp->wid - 1);
	}
	else if (c == 'p')
	{
		ft_putstr("0x");
		inp = (long long)va_arg(valist, void *);
		arginp->nb += ft_puthex(inp) + 2;
	}
}