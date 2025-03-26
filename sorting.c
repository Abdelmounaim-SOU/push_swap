/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asou <asou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 03:28:38 by asou              #+#    #+#             */
/*   Updated: 2025/03/26 23:17:17 by asou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_2(t_stack **s)
{
	if (*((*s)->number) > *((*s)->next->number))
		sa(s);
}

void	sorting_3(t_stack **s)
{
	if (*((*s)->number) > *((*s)->next->number) && \
			*((*s)->number) > *((*s)->next->next->number))
	{
		ra(s);
		if (*((*s)->number) > *((*s)->next->number))
			sa(s);
	}
	else if (*((*s)->number) < *((*s)->next->number) && \
			*((*s)->number) < *((*s)->next->next->number))
	{
		if (*((*s)->next->number) > *((*s)->next->next->number))
		{
			sa(s);
			ra(s);
		}
	}
	else
	{
		if (*((*s)->number) > *((*s)->next->number))
			sa(s);
		else
			rra(s);
	}
}

void	sorting_4(t_stack **a, t_stack **b)
{
	indexation(a);
	if (get_direction(*a, 0, 4))
	{
		while ((*a)->index != 0)
			ra(a);
	}
	else
	{
		while ((*a)->index != 0)
			rra(a);
	}
	pb(a, b);
	sorting_3(a);
	pa(a, b);
}

void	sorting_5(t_stack **a, t_stack **b)
{
	indexation(a);
	if (get_direction(*a, 0, 5))
	{
		while ((*a)->index != 0)
			ra(a);
	}
	else
	{
		while ((*a)->index != 0)
			rra(a);
	}
	pb(a, b);
	sorting_4(a, b);
	pa(a, b);
}

void	sorting_big(t_stack **a, t_stack **b)
{
	indexation(a);
	if (ft_lstsize(*a) <= 150)
		push_chunk(a, b, 20);
	else
		push_chunk(a, b, 35);
	sorting_back(a, b);
}
