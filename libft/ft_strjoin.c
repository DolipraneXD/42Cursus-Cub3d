/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:32:27 by moel-fat          #+#    #+#             */
/*   Updated: 2024/03/22 14:44:14 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	tlen;
	char	*s;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	tlen = ft_strlen(s1) + ft_strlen(s2) +1;
	s = (char *) malloc (tlen);
	if (s == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(s, s1, tlen);
	ft_strlcpy(s + ft_strlen(s1), s2, tlen);
	return (free(s1), s1 = NULL, s);
}
