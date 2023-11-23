/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:06:47 by mjong             #+#    #+#             */
/*   Updated: 2023/11/23 18:12:29 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0')
		{
			i++;
		}
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	totlen;
	char	*str;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = (char *)malloc(i + j + 1);			// allocate
	if (!str)
		return (NULL);
	str[i + j] = '\0';
	while (j--)
	{
		str[i + j] = s2[j];
	}
	while (i--)
	{
		str[i] = s1[i];
	}
	if (s1 != NULL)
		free((void *)s1);							// free
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char) c == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}
