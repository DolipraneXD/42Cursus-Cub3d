/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:59:46 by moel-fat          #+#    #+#             */
/*   Updated: 2024/02/03 14:23:27 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hay;
	char	*need;

	if (len == 0 && needle && haystack == NULL)
		return (NULL);
	need = (char *)needle;
	hay = (char *)haystack;
	i = 0;
	if (need[i] == '\0')
		return (hay);
	while (hay[i] != '\0' )
	{
		j = 0;
		while (need[j] == hay[j + i] && (i + j < len))
		{
			j++;
			if (need[j] == '\0')
				return (&hay[i]);
		}
		i++;
	}
	return (NULL);
}
