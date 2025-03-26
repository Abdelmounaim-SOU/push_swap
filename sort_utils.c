/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asou <asou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:28:10 by asou              #+#    #+#             */
/*   Updated: 2025/03/26 23:13:09 by asou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	main_direction(t_stack **s)
{
	long	x;
	int		c;
	t_stack	*p;

	p = *s;
	x = 0;
	c = ft_lstsize(*s) / 2;
	while (c >= 0)
	{
		if (p->index > p->next->index)
			x++;
		p = p->next;
		c--;
	}
	return (x);
}

void	push_chunk(t_stack **a, t_stack **b, int chunk_len)
{
	int		count;
	int		size;
	long	direction;

	count = 0;
	direction = main_direction(a);
	size = ft_lstsize(*a);
	while (!*a)
	{
		if ((*a)->index <= count)
		{
			pb(a, b);
			count++;
		}
		else if ((*a)->index < count + chunk_len)
		{
			pb(a, b);
			rb(b);
			count++;
		}
		else if (direction < size / 3)
			ra(a);
		else
			rra(a);
	}
}

int	is_sorted(t_stack **s)
{
	t_stack	*tmp;

	if (s == NULL || *s == NULL)
		return (0);
	tmp = *s;
	while (tmp->next != NULL)
	{
		if (*(tmp->number) > *(tmp->next->number))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
