/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_convert_upper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:25:58 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/08/13 21:50:31 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_hex_convert_upper(unsigned int number)
{
	char	*hex;
	char	hex_num[1000];
	char	temp[1000];
	int		index;
	int		i;

	hex = "0123456789ABCDEF";
	index = 0;
	while (number >= 16)
	{
		i = number % 16;
		temp[index] = hex[i];
		number /= 16;
		index++; 
	}
	temp[index] = hex[number];
	i = 0;
	while (index >= 0)
		hex_num[i++] = temp[index--];
	hex_num[i] = '\0';
	ft_putstr_pf(hex_num);
	return (i);
}
