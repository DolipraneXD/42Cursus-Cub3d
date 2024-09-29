/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:58:35 by moel-fat          #+#    #+#             */
/*   Updated: 2024/07/17 08:26:41 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif 
# include <libc.h>

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen_gnl(const char *str);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strdup_gnl(char *s1);
char	*ft_strndup(char *s1, size_t n);
char	*cnl(char **save, char *buffer, char *newline_pos);
char	*ft_return(ssize_t *count, char **save, char **line, char **buffer);

#endif