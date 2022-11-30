/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:01:14 by cbolat            #+#    #+#             */
/*   Updated: 2022/11/30 11:49:00 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*get_next_line(int fd);
char	*ft_read_to_left_str(int fd, char *dinamic_line);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_is_there_new_line(char *dinamic_line);
size_t	ft_strlen(char *str);
char	*ft_get_current_line(char *dinamic_line);
char	*ft_get_new_line(char *dinamic_line);

#endif
