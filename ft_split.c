/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asou <asou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:26:47 by asou              #+#    #+#             */
/*   Updated: 2025/03/26 01:44:13 by asou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	word_count(char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*get_words(char *s, char c, size_t	*start)
{
	char	*word;
	size_t	i;

	while (s[*start] && s[*start] == c)
		*(start) += 1;
	i = *start;
	while (s[*start] && s[*start] != c)
		*(start) += 1;
	word = (char *)malloc(*start - i + 1);
	if (word == NULL)
		return (NULL);
	ft_strlcpy(word, s + i, *start - i + 1);
	return (word);
}

static void	secure_free(char	**list, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		free(list[i++]);
	free(list);
}

char	**ft_split(char *s, char c)
{
	char	**list_splits;
	size_t	wordnum;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	wordnum = word_count(s, c);
	list_splits = (char **)malloc((wordnum + 1) * sizeof(char *));
	if (list_splits == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < wordnum)
	{
		list_splits[i] = get_words(s, c, &j);
		if (list_splits[i] == NULL)
		{
			secure_free(list_splits, i);
			return (NULL);
		}
		i++;
	}
	list_splits[i] = NULL;
	return (list_splits);
}
