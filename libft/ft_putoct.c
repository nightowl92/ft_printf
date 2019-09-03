/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:04:50 by stherkil          #+#    #+#             */
/*   Updated: 2019/09/01 20:53:57 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t		ft_putoct(intmax_t n)
{
	intmax_t result;

	result = 0;
	if (n < 8)
	{
		ft_putnbr(n);
		return (1);
	}
	else
	{
		result += ft_putoct(n / 8);
		result += ft_putoct(n % 8);
	}
	return (result);
}
