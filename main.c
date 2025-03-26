/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asou <asou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 02:12:37 by asou              #+#    #+#             */
/*   Updated: 2025/03/26 23:06:05 by asou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error!\n", 7);
	exit(1);
}

void	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		is_allowed(argv[i]);
		i++;
	}
}

t_stack	*stack_getter(char **arr)
{
	int		i;
	t_stack	*a;
	t_stack	*tmp;

	i = ft_arrlen(arr) - 1;
	a = ft_lstnew(ft_atoi(arr[i--]));
	if (!a)
	{
		ft_lstclear(&a, &free);
		exit(1);
	}
	while (i >= 0)
	{
		tmp = ft_lstnew(ft_atoi(arr[i]));
		if (!tmp)
		{
			ft_lstclear(&a, &free);
			exit(1);
		}
		ft_lstadd_front(&a, tmp);
		i--;
	}
	ft_free(arr);
	return (a);
}

void	sort(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 2)
		sorting_2(a);
	else if (size == 3)
		sorting_3(a);
	else if (size == 4)
		sorting_4(a, b);
	else if (size == 5)
		sorting_5(a, b);
	else
		sorting_big(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**arr;

	arr = validate_input(argc, argv);
	is_duplicated(arr);
	is_overflow(arr);
	b = NULL;
	a = stack_getter(arr);
	if (is_sorted(&a))
		return (ft_lstclear(&a, &free), 0);
	sort(&a, &b);
	ft_lstclear(&a, &free);
	ft_lstclear(&b, &free);
	return (0);
}
