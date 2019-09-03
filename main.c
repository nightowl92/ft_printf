#include "includes/ft_printf.h"

int main(void)
{
	printf("{%5p}", 0);
	printf("%ld%ld", 0l, 42l);
	printf("%hhi%hhi", 0, 42);
	printf("%hd%hd", (short int)0, (short int)42);
	printf("%.0p, %.p", 0, 0);
	printf("{%0-3d}", 0);
	return (0);
}