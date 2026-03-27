/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:45:42 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/08/13 21:50:14 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_hex_convert_lower(unsigned int number);
int	ft_hex_convert_p(void *ptr, char *hex);
int	ft_hex_convert_upper(unsigned int number);
int	ft_putnbr_pf(int n);
int	ft_putstr_pf(char *s);
int	ft_printf(const char *para, ...);
int	ft_putchar_pf(char c);
int	ft_putunbr_pf(unsigned int n);

#endif
