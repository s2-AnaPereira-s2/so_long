/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:49:27 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/06/23 21:49:30 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "so_long.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ns;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	ns = malloc((ft_strlen(s2) + ft_strlen(s1) + 1) * sizeof(char));
	if (!ns)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ns[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		ns[i++] = s2[j++];
	ns[i] = '\0';
	free(s1);
	return (ns);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*substr;
	int		i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		substr = malloc(1 * sizeof(char));
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (len--)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

char	*ft_strdup(char *s)
{
	char	*src_c;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
		i++;
	src_c = malloc((i + 1) * sizeof(char));
	if (!src_c)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		src_c[i] = s[i];
		i++;
	}
	src_c[i] = '\0';
	return (src_c);
}
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
int	ft_putnbr(int n)
{
	char	number;
	int		count;
	long	nb;

	nb = (long)n;
	count = 0;
	if (nb < 0)
	{
		count += write (1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		count += ft_putnbr(nb / 10);
	number = (nb % 10) + '0';
	count += write (1, &number, 1);
	return (count);
}
int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

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

int	ft_putunbr(unsigned int n)
{
	char	c;

	if (n > 9)
		ft_putunbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (ft_unsigned_length(n));
}

