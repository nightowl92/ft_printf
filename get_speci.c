#include "ft_printf.h"

void		applyf(va_list valist, t_data *arginp)
{
	if (arginp->flagno == 1)
		va_arg(valist, int);
}

void		applycps(va_list valist, t_data *arginp, char c)
{
	if (c == 's')
		ft_putstr(va_arg(valist, char*));
	else if (c == 'c')
		ft_putchar(va_arg(valist, int));
}

int			getspeci(va_list valist, t_data *arginp, char *s)
{
	int i;

	i = 1;
	if (*s == 'd' || *s == 'i')
		applydi(valist, arginp);
	else if (*s == 'u' || *s == 'o' || *s == 'x' || *s == 'X')
		applyuoxx(valist, arginp, *s);
	else if (*s == 'f')
		applyf(valist, arginp);
	else if (*s == 'c' || *s == 's' || *s == 'p')
		applycps(valist, arginp, *s);
	else
		i = 0;
	return (i);
}