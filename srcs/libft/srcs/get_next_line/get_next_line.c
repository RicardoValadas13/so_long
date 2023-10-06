/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:33:52 by rbenjami          #+#    #+#             */
/*   Updated: 2023/10/06 14:01:26 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n);

char	*get_next_line(int fd)
{
	static char	buff[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		if (fd >= 0 && fd <= FOPEN_MAX)
			ft_bzero(buff[fd], BUFFER_SIZE);
		return (NULL);
	}
	while (*buff[fd] || (read(fd, buff[fd], BUFFER_SIZE)) > 0)
	{
		line = thats_line(line, buff[fd]);
		if (check_newline(buff[fd]))
			break ;
	}
	return (line);
}
