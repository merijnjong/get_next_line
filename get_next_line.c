/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:06:50 by mjong             #+#    #+#             */
/*   Updated: 2023/11/30 16:30:22 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_remainder(char *staticbuf, char **line)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	while (staticbuf[i] != '\n' && staticbuf[i] != '\0')
		i++;
	if (staticbuf[i] == '\n')
		i++;
	if (staticbuf[i] == '\0')
		return (ft_free(&staticbuf));
	new = malloc(ft_strlen(staticbuf) - i + 1);
	if (!new)
	{
		ft_free(line);
		return (ft_free(&staticbuf));
	}
	while (staticbuf[i] != '\0')
		new[j++] = staticbuf[i++];
	ft_free(&staticbuf);
	new[j] = '\0';
	return (new);
}

char	*write_line(char *staticbuf)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (staticbuf[i] != '\n' && staticbuf[i] != '\0')
		i++;
	if (staticbuf[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = staticbuf[j];
		j++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_txt(char *staticbuf, int fd)
{
	ssize_t	bytes_read;
	char	*tempbuf;

	tempbuf = (char *)malloc(BUFFER_SIZE + 1);
	bytes_read = 1;
	if (!tempbuf)
		return (ft_free(&staticbuf));
	while (bytes_read > 0 && !ft_strchr(staticbuf, '\n'))
	{
		bytes_read = read(fd, tempbuf, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			tempbuf[bytes_read] = '\0';
			staticbuf = ft_strjoin(staticbuf, tempbuf);
			if (!staticbuf)
				return (ft_free(&tempbuf));
		}
	}
	ft_free(&tempbuf);
	if (bytes_read < 0)
		return (ft_free(&staticbuf));
	return (staticbuf);
}

char	*get_next_line(int fd)
{
	static char	*staticbuf = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	staticbuf = read_txt(staticbuf, fd);
	if (staticbuf == NULL)
		return (NULL);
	line = write_line(staticbuf);
	if (!line)
		return (ft_free(&staticbuf));
	staticbuf = get_remainder(staticbuf, &line);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	int		i;
// 	char	*line;

// 	fd = open("text.txt", O_RDONLY);
// 	i = 0;
// 	while (i < 11)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }
