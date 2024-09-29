/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:00:17 by moel-fat          #+#    #+#             */
/*   Updated: 2023/11/15 10:25:05 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dstptr ;
	const unsigned char	*srcptr;
	size_t				i;

	i = 0;
	dstptr = (unsigned char *)dst;
	srcptr = (const unsigned char *)src;
	if (dstptr == srcptr)
	{
		return (dst);
	}
	if (dstptr < srcptr)
	{
		ft_memcpy(dstptr, srcptr, len);
	}
	else
	{
		while (i < len)
		{
			dstptr[len - i - 1] = srcptr[len - i - 1];
			i++;
		}
	}
	return (dst);
}
