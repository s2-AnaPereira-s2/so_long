/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:00:50 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/08/13 22:00:32 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *nbr)
{
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	while (*nbr)
	{
		while (*nbr == ' ' || (*nbr >= 9 && *nbr <= 13))
			nbr++;
		if (*nbr == '+' || *nbr == '-')
		{
			if (*nbr == '-')
				sign = -1;
			nbr++;
		}
		while (*nbr >= '0' && *nbr <= '9')
		{
			result = (result * 10 + (*nbr++ - '0'));
		}
		return (result * sign);
	}
	return (result * sign);
}
