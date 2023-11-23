/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:06:50 by mjong             #+#    #+#             */
/*   Updated: 2023/11/23 17:38:45 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*three_remainder(char *staticbuf)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	while (staticbuf[i] != '\n')
	{
		i++;
	}
	while (staticbuf[i] == '\n')
	{
		i++;
	}
	new = (char *)malloc(ft_strlen((staticbuf) - i + 1));	// allocate D
	if (!new)
	{
		ft_free(&staticbuf);								// free if it fails
	}
	new[0] = '\0';
	while (staticbuf[i] != '\0')
	{
		new[j] = staticbuf[i];
		i++;
		j++;
	}
	new[j] = '\0';
	// printf("test func three: %s\n", new);
	free(staticbuf);										// free A
	staticbuf = NULL;
	return (new);
}

char	*two_writeline(char *staticbuf)
{
	int i;
	char *line;

	i = 0;
	while (staticbuf[i] != '\n' || !staticbuf)
	{
		i++;
	}
	line = (char *)malloc(i + 1);							// allocate C
	if (!line)
	{
		ft_free(&staticbuf);								// free if it fails
	}
	line[0] = '\0';
	i = 0;
	while (staticbuf[i] != '\n')
	{
		line[i] = staticbuf[i];
		i++;
	}
	line[i] = '\0';
	// printf("test fun two: %s\n", line);
	return (line);
}

char	*one_readtxt(char *staticbuf, int fd)
{
	ssize_t	bytes_read;
	char	*tempbuf;
	
	staticbuf = (char *)malloc(BUFFER_SIZE + 1);			// allocate A
	tempbuf = (char *)malloc(BUFFER_SIZE + 1);				// allocate B
	if (!staticbuf || !tempbuf)
	{
		ft_free(&staticbuf);								// free if it fails
	}
	tempbuf[0] = '\0';
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(tempbuf, '\n'))
	{
		bytes_read = read(fd, tempbuf, BUFFER_SIZE);
		staticbuf = ft_strjoin(staticbuf, tempbuf);
		tempbuf[bytes_read] = '\0';
	}
	// printf("test buf func = %s\n", buf);
	free(tempbuf);											// free B & D
	tempbuf = NULL;
	return (staticbuf);
}

char	*get_next_line(int fd)
{
	static char	*staticbuf = NULL;
	char		*line;

	staticbuf = one_readtxt(staticbuf, fd);
	// printf("test func one = %s\n", buf);
	line = two_writeline(staticbuf);
	// printf("test func two = %s\n", line);
	staticbuf = three_remainder(staticbuf);
	return (line);
}

int	main(void)
{
	int	fd;
	int	i = 0;
	char *line;

	fd = open("text.txt", O_RDONLY);
	while (i < 7)
	{
		line = get_next_line(fd);
		printf("%s", line);
		i++;
	}
	free(line);											// free C
	close(fd);
	return (0);
}
