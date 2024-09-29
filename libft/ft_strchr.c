/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:58:35 by moel-fat          #+#    #+#             */
/*   Updated: 2023/11/14 13:30:39 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
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
