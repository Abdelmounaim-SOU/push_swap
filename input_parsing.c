/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asou <asou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 02:19:34 by asou              #+#    #+#             */
/*   Updated: 2025/03/26 22:58:57 by asou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdlib.h>
#include <limits.h>

char	**ft_join(char **s1, char **s2)
{
	int		i;
	int		j;
	char	**result;

	if (!s1)
		return (s2);
	result = malloc(sizeof(char *) * (ft_tablen(s1) + ft_tablen(s2) + 1));
	if (!result)
		(ft_free(s1), ft_free(s2), exit(1));
	i = 0;
	while (i < ft_tablen(s1))
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_tablen(s2))
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = NULL;
	return (free(s1), free(s2), result);
}

char	**validate_input(int argc, char **argv)
{
	int		i;
	char	**spl;
	char	**arr;

	i = 0;
	arr = NULL;
	if (argc <= 1)
		exit(1);
	check_args(argc, argv);
	while (i < argc - 1)
	{
		spl = ft_split(argv[i + 1], ' ');
		if (!spl)
			(ft_free(arr), error());
		arr = ft_join(arr, spl);
		i++;
	}
	return (arr);
}

int	**convert_arr(char **s)
{
	int	i;
	int	**result;

	result = malloc(sizeof(int *) * (ft_tablen(s) + 1));
	if (!result)
		(ft_free(s), exit(1));
	i = 0;
	while (s[i])
	{
		result[i] = malloc(sizeof(int));
		if (!result[i])
			(ft_free(s), ft_free_int(result, i), exit(i));
		i++;
	}
	i = 0;
	while (s[i])
	{
		*result[i] = ft_atoi(s[i]);
		i++;
	}
	return (result);
}

void	is_duplicated(char **s)
{
	int	i;
	int	j;
	int	**arr;

	arr = convert_arr(s);
	i = ft_tablen(s) - 1;
	while (i)
	{
		j = 0;
		while (j < i)
		{
			if (*arr[i] == *arr[j])
				(ft_free_int(arr, ft_tablen(s)), ft_free(s), error());
			j++;
		}
		i--;
	}
	ft_free_int(arr, ft_tablen(s));
}

void	is_overflow(char **arr)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (arr[i])
	{
		k = ft_strlen(arr[i]);
		j = 0;
		if (arr[i][j] == '-' || arr[i][j] == '+')
		{
			j++;
			k--;
		}
		while (arr[i][j++] == '0')
			k--;
		if (k > 10)
			(ft_free(arr), error());
		if (k == 10 && (ft_atoi(arr[i]) > INT_MAX || \
				ft_atoi(arr[i]) < INT_MIN))
			(ft_free(arr), error());
		i++;
	}
}
