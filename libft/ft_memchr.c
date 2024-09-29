/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:50:07 by moel-fat          #+#    #+#             */
/*   Updated: 2023/11/13 20:04:37 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr;
	unsigned char		cc;

	cc = (unsigned char)c;
	ptr = s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == cc)
		{
			return ((void *)(ptr + i));
		}
		i++;
	}
	return (NULL);
}
