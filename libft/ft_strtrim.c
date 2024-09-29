/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:41:59 by moel-fat          #+#    #+#             */
/*   Updated: 2023/11/15 10:26:16 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	tlen;
	char	*ptr;

	if (s1 == NULL || set == NULL )
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	if (start == ft_strlen(s1))
		return (ft_strdup(""));
	while (start < ft_strlen(s1) && ft_strchr(set, s1[start]))
	{
		start++;
	}
	while (end > start && ft_strchr(set, s1[end]))
	{
		end--;
	}
	tlen = end - start + 1;
	ptr = (char *)malloc(tlen +1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1 + start, tlen + 1);
	return (ptr);
}
