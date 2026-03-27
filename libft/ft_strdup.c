/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:12:55 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/07/31 15:09:36 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*src_c;
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	src_c = (char *)malloc((i + 1) * sizeof(char));
	if (!src_c)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		src_c[i] = s[i];
		i++;
	}
	src_c[i] = '\0';
	if (!src_c)
		return (NULL);
	return (src_c);
}
