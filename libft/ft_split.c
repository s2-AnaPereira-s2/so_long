/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:12:44 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/07/31 15:09:26 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_total_words(char const *s, char c)
{
	int		total_words;
	int		i;

	i = 0;
	total_words = 0;
	if (s[0] != '\0' && s[0] != c)
		total_words++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
		{
			i++;
			total_words++; 
		}
		else
			i++;
	}
	return (total_words);
}

static int	ft_start(char const *s, char c, int i)
{
	while (s[i] == c && s[i] != '\0') 
		i++;
	return (i);
}

static int	ft_end(char const *s, char c, int start)
{
	while (s[start] && s[start] != c)
		start++;
	return (start);
}

static char	**ft_free_split(char **split, int index)
{
	while (--index >= 0)
	{
		free(split[index]);
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		start;
	int		index;
	int		i;

	split = ft_calloc(ft_total_words(s, c) + 1, sizeof(char *));
	if (!split)
		return (NULL);
	index = 0;
	i = 0;
	while (s[i] != '\0')
	{
		start = ft_start(s, c, i);
		if (start == (int)ft_strlen(s))
			break ;
		i = ft_end(s, c, start);
		split[index] = ft_substr(s, start, i - start);
		if (!split[index])
			return (ft_free_split(split, index));
		index++;
	}
	split[index] = NULL;
	return (split);
}
