/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:07:12 by mjong             #+#    #+#             */
/*   Updated: 2023/11/16 17:51:18 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 300
#endif
// ssize_t	read_result(int fd);
// char	*write_from_fd(int fd);

ssize_t	count_first_line(int fd);
char 	*write_first_line(int fd);

#endif