/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:42:14 by cbolat            #+#    #+#             */
/*   Updated: 2022/11/30 11:42:15 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *dest, char *src);
char	*ft_is_there_new_line(char *str);
char	*ft_get_current_line(char *str);
char	*ft_get_new_line(char *str);
size_t	ft_strlen(char *str);
char	*ft_read_to_left_str(int fd, char *left_str);

#endif
