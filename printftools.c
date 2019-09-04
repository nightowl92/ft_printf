#include "ft_printf.h"

intmax_t       get_signed(va_list valist, t_data *arginp)
{
    uintmax_t n;

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

uintmax_t       get_unsigned(va_list valist, t_data *arginp)
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