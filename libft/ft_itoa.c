/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:40:07 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/05/20 15:54:43 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_length(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (count = 11);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	if (n < 9)
	{
		count++;
		return (count);
	}
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_intmin(char *number)
{
	char	*intmin;

	intmin = "-2147483648";
	number = ft_memcpy(number, intmin, 11);
	return (number);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		size;

	size = ft_length(n);
	number = malloc((size + 1) * sizeof(char));
	if (!number)
		return (NULL);
	number[size] = '\0';
	if (n == -2147483648)
		number = ft_intmin(number);
	if (n < 0)
	{
		n *= -1;
		number[0] = '-';
	}
	if (n == 0)
		number[0] = '0';
	while (n > 0)
	{
		number[(size--) - 1] = (n % 10) + '0';
		n /= 10;
	}
	return (number);
}
