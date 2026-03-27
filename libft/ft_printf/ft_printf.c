/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:35:46 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/08/13 21:49:56 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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
		return (ft_putstr_pf(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_hex_convert_p(va_arg(args, void *), "0123456789abcdef"));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_pf(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunbr_pf(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_hex_convert_lower(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (ft_hex_convert_upper(va_arg(args, unsigned int)));
	else if (c == '%')
		return (ft_putchar_pf('%'));
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
