/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:04:50 by stherkil          #+#    #+#             */
/*   Updated: 2019/08/24 15:18:57 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putoct(int n)
{
	int result;

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
