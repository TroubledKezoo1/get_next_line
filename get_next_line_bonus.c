/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:41:52 by cbolat            #+#    #+#             */
/*   Updated: 2022/11/30 12:06:53 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_to_left_str(int fd, char *dinamic_line)
{
	int		readable_bytes;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	readable_bytes = 1;
	while (ft_is_there_new_line(dinamic_line) == NULL && readable_bytes != 0)
	{
		readable_bytes = read(fd, buffer, readable_bytes);
		if (readable_bytes == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[readable_bytes] = '\0';
		dinamic_line = ft_strjoin(dinamic_line, buffer);
	}
	free(buffer);
	return (dinamic_line);
}

char	*get_next_line(int fd)
{
	static char	*dinamic_line[4096];
	char		*printable_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	dinamic_line[fd] = ft_read_to_left_str(fd, dinamic_line[fd]);
	if (!dinamic_line[fd])
		return (NULL);
	printable_line = ft_get_current_line(dinamic_line[fd]);
	dinamic_line[fd] = ft_get_new_line(dinamic_line[fd]);
	return (printable_line);
}
/*
int	main()
{
    int cemalfd;
    int burakfd;
    int tosnafd;
    int sancakfd;

    cemalfd = open("cemal.txt",O_RDONLY);
    tosnafd = open("tosna.txt",O_RDONLY);
    burakfd = open("burak.txt",O_RDONLY);
    sancakfd = open("daldaban.txt",O_RDONLY);

    get_next_line(cemalfd);
    get_next_line(burakfd);
    printf("%s",get_next_line(cemalfd));
    while ((1));

    //printf("%d-%d-%d-%d\n",cemalfd,tosnafd,burakfd,sancakfd);

}
*/
