/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:35:46 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/06/23 22:05:11 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

static int	check(const char c, va_list args)
{
	char	ch;

	if (c == 'c')
	{
		ch = (char)va_arg(args, int);
		write(1, &ch, 1);
		return (1);
	}
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *para, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, para);
	i = 0;
	count = 0;
	while (para[i])
	{
		if (para[i] == '%')
		{
			i++;
			count += check(para[i], args);
			i++;
		}
		else
		{
			write(1, &para[i], 1);
			i++;
			count++;
		}
	}
	va_end(args);
	return (count);
}
