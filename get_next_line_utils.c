/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:42:03 by cbolat            #+#    #+#             */
/*   Updated: 2022/11/30 11:42:04 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_is_there_new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (*(str + i) != '\0')
	{
		if (*(str + i) == '\n')
			return (str + i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	i = -1;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == NULL)
		return (NULL);
	if (s1)
		while (s1[++i] != '\0')
			res[i] = s1[i];
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

char	*ft_get_current_line(char *dinamic_line)
{
	int		i;
	char	*str;

	i = 0;
	if (!dinamic_line[0])
		return (0);
	while (dinamic_line[i] != '\0' && dinamic_line[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (dinamic_line[i] != '\0' && dinamic_line[i] != '\n')
	{
		str[i] = dinamic_line[i];
		i++;
	}
	if (dinamic_line[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_get_new_line(char *dinamic_line)
{
	int		i;
	char	*str;
	int		j;

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
