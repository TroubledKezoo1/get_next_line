/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:42:08 by cbolat            #+#    #+#             */
/*   Updated: 2022/11/30 13:44:18 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line_left_to_right(int fd, char *dinamic_line)
{
	char	*buff;
	int		rd_bytes;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	rd_bytes = 1;
	while (ft_is_there_new_line(dinamic_line) == NULL && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		dinamic_line = ft_strjoin(dinamic_line, buff);
	}
	free(buff);
	return (dinamic_line);
}

char	*get_next_line(int fd)
{
	char		*printable_line;
	static char	*dinamic_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	dinamic_line = ft_read_line_left_to_right(fd, dinamic_line);
	if (!dinamic_line)
		return (NULL);
	printable_line = ft_get_current_line(dinamic_line);
	dinamic_line = ft_get_new_line(dinamic_line);
	return (printable_line);
}


int main()
{
	int fd;
	int fd2;
	char	*txt = "cemala.txt";
	char	*txt2 = "cemaladaa.txt";
	FILE *file = fopen(txt,"w+");
	FILE *file2 = fopen(txt2,"w+");
	fprintf(file,"cemal\nbolat");
	fprintf(file2,"cemal\nbolat");
	fprintf(file2,"gtu\n42");
	fclose(file);
	fd = open(txt,O_RDWR);
	fd2 = open(txt2,O_RDONLY);
	write(fd,"cemalbola\ngtu42}\0",16);
	write(fd,"cemalbola\ngtu42}\0",16);
	printf("%d ",fd);
	printf("%d\n",fd2);
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));

	//while (1);
	//printf("%d\n",fd);
}

