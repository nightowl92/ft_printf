

#include "ft_printf.h"

int main(void)
{
	int a = 12020;

	printf("%+010.1f\n", 123.01);
	ft_printf("%+-010.1f\n", 123.01);
	return (0);
}
