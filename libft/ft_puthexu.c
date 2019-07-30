/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:04:50 by stherkil          #+#    #+#             */
/*   Updated: 2019/07/29 11:54:53 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthexu(int n)
{
	if (n < 10)
		ft_putnbr(n);
	else if (n < 16)
		ft_putchar(n - 10 + 'A');
	else
	{
		ft_puthexu(n / 16);
		ft_puthexu(n % 16);
	}
}