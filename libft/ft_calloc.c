/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:56:32 by moel-fat          #+#    #+#             */
/*   Updated: 2023/11/22 15:58:29 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	temp;

	temp = count * size;
	if (count && (temp / count != size))
		return (NULL);
	ptr = malloc (count * size);
	if (ptr != NULL)
	{
		ft_bzero(ptr, count * size);
		return (ptr);
	}
	return (NULL);
}
