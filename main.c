

#include "ft_printf.h"

int main(void)
{
	int a = 12020;

printf("%p\n", (void *) &a);
	ft_printf("%p\n", (void *) &a);
printf("%12.12d\n", 123);
	ft_printf("%12.12d\n", 123);
printf("%12.12d %s\n", 123, "wesh ok");
	ft_printf("%12.12d %s\n", 123, "wesh ok");


	return (0);
}
