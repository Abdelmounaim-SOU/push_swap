/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asou <asou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 23:11:31 by asou              #+#    #+#             */
/*   Updated: 2025/03/26 22:56:46 by asou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdlib.h>

void	ft_free(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	ft_free_int(int **arr, int len)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}

int	ft_tablen(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}

void	is_allowed(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		exit(1);
	if (!s[0])
		error();
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != '+' && \
			s[i] != '-' && s[i] != ' ')
			error();
		if (s[i] == '+' || s[i] == '-')
		{
			if (i != 0 && s[i - 1] != ' ')
				error();
			if (s[i + 1] < '0' || s[i + 1] > '9')
				error();
		}
		i++;
	}
}
