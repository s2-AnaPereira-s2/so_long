/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:13:09 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/07/31 15:09:47 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	dst_len = i;
	src_len = ft_strlen(src);
	if (dst_len >= size)
		return (size + src_len);
	if (size > 0)
	{
		j = 0;
		while (src[j] && (dst_len + j < size - 1))
		{
			dst[dst_len + j] = src[j];
			j++;
		}
		dst[dst_len + j] = '\0';
	}
	return (dst_len + src_len);
}
