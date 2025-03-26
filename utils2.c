/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asou <asou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:48:23 by asou              #+#    #+#             */
/*   Updated: 2025/03/26 23:17:53 by asou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdelone(t_stack *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	if (lst->number != NULL)
		(*del)(lst->number);
	free(lst);
}

void	ft_lstclear(t_stack **lst, void (*del)(void*))
{
	t_stack	*p;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		p = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = p;
	}
}

void	ft_lstiter(t_stack *lst, void (*f)(int *))
{
	if (f == NULL)
		return ;
	while (lst != NULL)
	{
		(*f)(lst->number);
		lst = lst->next;
	}
}

t_stack	*ft_lstnew(int num)
{
	t_stack	*ptr;
	int		*content;

	content = malloc(sizeof(int));
	if (content == NULL)
		return (NULL);
	*content = num;
	ptr = (t_stack *)malloc(sizeof(t_stack));
	if (ptr == NULL)
		return (free(content), NULL);
	ptr->number = content;
	ptr->next = NULL;
	return (ptr);
}
