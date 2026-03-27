/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_convert_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:14:04 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/08/13 21:50:41 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_hex_convert_p(void *ptr, char *hex)
{
	unsigned long	num;
	char			temp[1000];
	char			hex_num[1000];
	int				index;
	int				i;

	num = (unsigned long)ptr;
	if (!ptr)
		return (write(1, "(nil)", 5));
	index = 0;
	while (num >= 16)
	{
		i = num % 16;
		temp[index++] = hex[i];
		num /= 16;
	}
	temp[index] = hex[num];
	i = 2;
	hex_num[0] = '0';
	hex_num[1] = 'x';
	while (index >= 0)
		hex_num[i++] = temp[index--];
	hex_num[i] = '\0';
	ft_putstr_pf(hex_num);
	return (i);
}
