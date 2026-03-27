/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:19:25 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/08/13 21:53:26 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*ns;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	ns = malloc((ft_strlen_gnl(s2) + ft_strlen_gnl(s1) + 1) * sizeof(char));
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

char	*ft_substr_gnl(char *s, int start, int len)
{
	char	*substr;
	int		i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen_gnl(s))
	{
		substr = malloc(1 * sizeof(char));
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (len > ft_strlen_gnl(s) - start)
		len = ft_strlen_gnl(s) - start;
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (len--)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

char	*ft_strdup_gnl(char *s)
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
