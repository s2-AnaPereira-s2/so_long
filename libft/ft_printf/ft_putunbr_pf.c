/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:30:49 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/08/13 21:56:38 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ft_unsigned_length(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_putunbr_pf(unsigned int n)
{
	char	c;

	if (n > 9)
		ft_putunbr_pf(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (ft_unsigned_length(n));
}
