/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:34:53 by moel-fat          #+#    #+#             */
/*   Updated: 2023/11/15 10:26:11 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ss;
	char	d;
	size_t	len;

	ss = (char *)s;
	d = (char)c;
	len = ft_strlen(ss);
	if (d == '\0')
	{
		return (&ss[len]);
	}
	while (len > 0)
	{
		len--;
		if (ss[len] == d)
		{
			return (&ss[len]);
		}
	}
	return (NULL);
}
