/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asou <asou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:26:41 by asou              #+#    #+#             */
/*   Updated: 2025/03/26 22:59:21 by asou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **s)
{
	t_stack	*tmp;

	if (s == NULL || *s == NULL || (*s)->next == NULL)
		return ;
	tmp = (*s)->next;
	(*s)->next = tmp->next;
	tmp->next = *s;
	*s = tmp;
}

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (src == NULL || *src == NULL || dst == NULL)
		return ;
	tmp = (*src)->next;
	ft_lstadd_front(dst, *src);
	*src = tmp;
}

void	rotate(t_stack **s)
{
	t_stack	*tmp;

	if (s == NULL || *s == NULL || (*s)->next == NULL)
		return ;
	tmp = (*s)->next;
	ft_lstadd_back(s, *s);
	(*s)->next = NULL;
	*s = tmp;
}

void	rev_rotate(t_stack **s)
{
	t_stack	*last;
	t_stack	*blast;

	if (s == NULL || *s == NULL || (*s)->next == NULL)
		return ;
	last = ft_lstlast(*s);
	blast = ft_lst_beflast(*s);
	blast->next = NULL;
	ft_lstadd_front(s, last);
	*s = last;
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
