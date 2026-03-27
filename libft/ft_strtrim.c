/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:14:07 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/05/20 20:55:18 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	ft_start(const char *s1, const char *set)
{
	int	start;
	int	j;

	start = 0;
	while (s1)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[start] != set[j])
				j++;
			else if (s1[start] == set[j])
				break ;
		}
		if (s1[start] != set[j])
			break ;
		start++;
	}
	return (start);
}

int	ft_end(const char *s1, const char *set)
{
	int	end;
	int	j;

	end = ft_strlen(s1);
	while (s1)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[end - 1] != set[j])
				j++;
			else if (s1[end - 1] == set[j])
				break ;
		}
		if (s1[end - 1] != set[j])
			break ;
		end--;
	}
	return (end);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int			start;
	int			end;
	char		*trim;

	if (!s1)
		return (NULL);
	if (!set && set[0] == '\0')
		return ((char *)s1);
	end = ft_end(s1, set);
	start = ft_start(s1, set);
	trim = ft_substr(s1, start, (end - start));
	return (trim);
}
