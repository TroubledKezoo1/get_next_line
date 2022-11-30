/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:41:56 by cbolat            #+#    #+#             */
/*   Updated: 2022/11/30 11:49:58 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_is_there_new_line(char *dinamic_line)
{
	int	i;

	i = 0;
	if (!dinamic_line)
		return (NULL);
	while (*(dinamic_line + i) != '\0')
	{
		if (*(dinamic_line + i) == '\n')
			return (dinamic_line + i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char *) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_get_current_line(char *dinamic_line)
{
	int		i;
	char	*line;

	i = 0;
	if (dinamic_line[0] == EOF)
		return (0);
	while (dinamic_line[i] != '\0' && dinamic_line[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (dinamic_line[i] != '\0' && dinamic_line[i] != '\n')
	{
		line[i] = dinamic_line[i];
		i++;
	}
	if (dinamic_line[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_get_new_line(char *dinamic_line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (dinamic_line[i] != '\0' && dinamic_line[i] != '\n')
		i++;
	if (dinamic_line[i] == '\0')
	{
		free(dinamic_line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(dinamic_line) - i - 1));
	if (!str)
		return (NULL);
	i++;
	while (dinamic_line[i] != '\0')
		str[j++] = dinamic_line[i++];
	str[j] = '\0';
	free(dinamic_line);
	return (str);
}
