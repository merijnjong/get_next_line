/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:06:50 by mjong             #+#    #+#             */
/*   Updated: 2023/11/16 18:17:32 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	count_first_line(int fd)
{
	char	*result;
	ssize_t	count;

	result = write_first_line(fd);
	count = 0;
	while (result[count] != '\0')
	{
		count++;
	}
	free(result);								// free 2
	return (count);
}

char	*write_first_line(int fd)
{
	char		*buf;
	char		*line;
	int			i;

	buf = (char *)malloc(BUFFER_SIZE); 			// allocate 1
	line = (char *)malloc(BUFFER_SIZE); 		// allocate 2
	i = 0;
	if (buf == NULL)
		return (0);
	read(fd, buf, BUFFER_SIZE);					// read function writes in buf
	while (buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	free(buf);									// free 1
	return (line);
}

int	main(void)
{
	int		fd;
	ssize_t	result;

	fd = open("text.txt", O_RDONLY);
	result = count_first_line(fd);
	printf("%zu", result);
	close(fd);
	return (0);
}