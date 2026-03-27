/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:28:24 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/05/16 16:51:39 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	int				size;
	char			*new_s;

	size = ft_strlen(s);
	new_s = malloc((size + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		new_s[index] = (*f)(index, s[index]);
		index++;
	}
	new_s[size] = '\0';
	return (new_s);
}
