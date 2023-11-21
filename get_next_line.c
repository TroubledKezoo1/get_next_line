/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunus <yunus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:47:14 by cbolat            #+#    #+#             */
/*   Updated: 2023/11/18 18:08:20 by yunus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_up_to_new_line(char *line)
{
	int		counter;
	char	*temp;

	counter = 0;
	if (!line[counter])
		return (NULL);
	while (line[counter] && line[counter] != '\n')
		counter++;
	temp = (char *)malloc(sizeof(char) * (counter + 2));
	if (!temp)
		return (NULL);
	counter = 0;
	while (line[counter] && line[counter] != '\n')
	{
		temp[counter] = line[counter];
		counter++;
	}
	if (line[counter] == '\n')
	{
		temp[counter] = line[counter];
		counter++;
	}
	temp[counter] = '\0';
	return (temp);
}

char	*get_new_value(int fd, char *mainbuffer)
{
	char	*buffer;
	int		 check;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	check = 1;
	while (!ft_strchr(mainbuffer, '\n') && check != 0)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[check] = '\0';
		mainbuffer = ft_strjoin(mainbuffer, buffer);
	}
	free(buffer);
	return (mainbuffer);
}

char	*get_after_new_line(char *line)
{
	int		newlinecounter;
	int		aftercounter;
	char	*temp;

	newlinecounter = 0;
	while (line[newlinecounter] && line[newlinecounter] != '\n')
		newlinecounter++;
	if (!line[newlinecounter])
	{
		free(line);
		return (NULL);
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(line) - newlinecounter + 1));
	if (!temp)
		return (NULL);
	newlinecounter++;
	aftercounter = 0;
	while (line[newlinecounter])
		temp[aftercounter++] = line[newlinecounter++];
	temp[aftercounter] = '\0';
	free(line);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*mainbuffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	mainbuffer = get_new_value(fd, mainbuffer);
	if (!mainbuffer)
		return (NULL);
	line = get_up_to_new_line(mainbuffer);
	mainbuffer = get_after_new_line(mainbuffer);
	return (line);
}
