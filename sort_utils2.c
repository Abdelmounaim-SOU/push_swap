/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asou <asou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:39:43 by asou              #+#    #+#             */
/*   Updated: 2025/04/10 20:32:48 by asou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexation(t_stack **s)
{
	t_stack	*i;
	t_stack	*j;

	i = *s;
	while (i)
	{
		i->index = 0;
		j = *s;
		while (j)
		{
			if (*(i->number) > *(j->number))
				i->index += 1;
			j = j->next;
		}
		i = i->next;
	}
}

int	get_direction(t_stack *s, int index, int size)
{
	int	i;

	i = 0;
	while (s->index != index)
	{
		i++;
		s = s->next;
	}
	if (i <= size / 2)
		return (1);
	return (0);
}

void	rotate_push(t_stack **s, int index)
{
	while ((*s)->index != index)
		rb(s);
}

void	reverse_rotate_push(t_stack **s, int index)
{
	while ((*s)->index != index)
		rrb(s);
}

void	sorting_back(t_stack **a, t_stack **b)
{
	int	i;
	int	size;

	size = ft_lstsize(*b);
	i = size - 1;
	while (*b != NULL)
	{
		size = ft_lstsize(*b);
		if (get_direction(*b, i, size))
			rotate_push(b, i);
		else
			reverse_rotate_push(b, i);
		pa(a, b);
		i--;
	}
}
