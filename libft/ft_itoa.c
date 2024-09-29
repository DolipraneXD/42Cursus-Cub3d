/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:24:04 by moel-fat          #+#    #+#             */
/*   Updated: 2023/11/13 19:54:15 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calllen(long n)
{
	size_t	i;

	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*convert(char *s, long c, int len, int nn)
{
	int	i;

	i = len;
	while (len > 0)
	{
		s[len - 1] = (c % 10) + '0';
		c /= 10;
		len--;
	}
	if (nn < 0)
		s[0] = '-';
	s[i] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*s;
	long	c;
	long	nn;

	nn = n;
	c = nn;
	if (nn == 0)
		i = 1;
	else if (nn < 0)
	{
		i = calllen(-nn) + 1;
		c = c * (-1);
	}
	else
		i = calllen(nn);
	len = i;
	s = (char *) malloc (len + 1);
	if (s == NULL)
		return (NULL);
	convert(s, c, len, nn);
	return (s);
}
