/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:58:46 by moel-fat          #+#    #+#             */
/*   Updated: 2024/07/17 08:31:32 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(const char *s, int c)
{
	char	d;
	char	*ss;
	size_t	i;

	ss = (char *) s;
	d = (char) c;
	i = 0;
	while (ss[i])
	{
		if (ss[i] != d)
			i++;
		else
			return (&ss[i]);
	}
	if (d == '\0')
	{
		return (&ss[i]);
	}
	return (NULL);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen_gnl(src);
	i = 0;
	if (dstsize == 0)
	{
		return (srclen);
	}
	else
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		return (srclen);
	}
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	tlen;
	char	*s;

	if (s1 == NULL)
		return (ft_strdup_gnl(s2));
	if (s2 == NULL)
		return (ft_strdup_gnl(s1));
	tlen = ft_strlen_gnl(s1) + ft_strlen_gnl(s2) +1;
	s = (char *) malloc (tlen);
	if (s == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy_gnl(s, s1, tlen);
	ft_strlcpy_gnl(s + ft_strlen_gnl(s1), s2, tlen);
	return (free(s1), s1 = NULL, s);
}

char	*ft_strdup_gnl(char *s1)
{
	size_t	i;
	size_t	len;
	char	*ptr;

	i = 0;
	len = ft_strlen_gnl(s1) + 1;
	ptr = (char *) malloc(len * sizeof(char));
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strndup(char *s1, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *) malloc((n + 1) * sizeof(char));
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (i < n && s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
