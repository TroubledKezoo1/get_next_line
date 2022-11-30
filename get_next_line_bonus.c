/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:46:53 by cbolat            #+#    #+#             */
/*   Updated: 2022/11/30 16:17:38 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line_bonus.h"

char	*ft_read_left_to_right(int fd, char *d_line)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (0);
	rd_bytes = 1;
	while (!ft_strchr(d_line, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (0);
		}
		buff[rd_bytes] = '\0';
		d_line = ft_strjoin(d_line, buff);
	}
	free(buff);
	return (d_line);
}

char	*get_next_line(int fd)
{
	char		*current_line;
	static char	*d_line[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	d_line[fd] = ft_read_left_to_right(fd, d_line[fd]);
	if (!d_line[fd])
		return (0);
	current_line = ft_get_line(d_line[fd]);
	d_line[fd] = ft_new_dinamic_line(d_line[fd]);
	return (current_line);
}
