/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 14:31:57 by stherkil          #+#    #+#             */
/*   Updated: 2019/07/29 14:40:17 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numlen(int nb)
{
	int i;

	i = 0;
	if (nb < 0)
	{
		i = 1;
		nb = -nb;
	}
	while ((nb /= 10))
		++i;
	return (i);
}
