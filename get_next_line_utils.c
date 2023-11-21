/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:47:09 by cbolat            #+#    #+#             */
/*   Updated: 2023/10/09 00:36:59 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *d_line, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!d_line)
	{
		d_line = (char *)malloc(1 * sizeof(char));
		d_line[0] = '\0';
	}
	if (!d_line || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(d_line) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (d_line)
		while (d_line[++i] != '\0')
			str[i] = d_line[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(d_line) + ft_strlen(buff)] = '\0';
	free(d_line);
	return (str);
}

