/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:04:50 by stherkil          #+#    #+#             */
/*   Updated: 2019/09/01 20:55:05 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t		ft_puthexu(intmax_t n)
{
	intmax_t result;

	result = 0;
	if (n < 10)
	{
		ft_putnbr(n);
		return (1);
	}
	else if (n < 16)
	{
		ft_putchar(n - 10 + 'A');
		return (1);
	}
	else
	{
		result += ft_puthexu(n / 16);
		result += ft_puthexu(n % 16);
	}
	return (result);
}
