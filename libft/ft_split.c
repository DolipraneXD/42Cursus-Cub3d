/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:12:12 by moel-fat          #+#    #+#             */
/*   Updated: 2023/11/21 08:52:52 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	wcount;
	size_t	i;

	i = 0;
	wcount = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			wcount++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (wcount);
}

static char	*word_maker(const char *s, size_t start, size_t end)
{
	size_t	wlen;
	size_t	i;
	char	*word;

	wlen = end - start;
	i = 0;
	word = (char *)malloc(wlen + 1);
	if (word == NULL)
		return (NULL);
	while (i < wlen)
	{
		word[i] = s[start + i];
		i++;
	}
	word[wlen] = '\0';
	return (word);
}

static void	befree(char **tsplit)
{
	size_t	i;

	i = 0;
	while (tsplit[i])
	{
		free(tsplit[i]);
		i++;
	}
	free(tsplit);
}

static char	**fill_and_free(char **tsplit, const char *s, char c, size_t wc)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i] && j < wc)
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			tsplit[j] = word_maker(s, start, i);
			if (tsplit[j] == NULL)
			{
				befree(tsplit);
				return (NULL);
			}
			j++;
		}
		else
			i++;
	}
	return (tsplit[j] = NULL, tsplit);
}

char	**ft_split(char const *s, char c)
{
	size_t	wordcount;
	char	**tsplit;

	if (s == NULL)
		return (NULL);
	wordcount = count_words(s, c);
	tsplit = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (tsplit == NULL)
		return (NULL);
	if (fill_and_free(tsplit, s, c, wordcount) == NULL)
		return (NULL);
	return (tsplit);
}
