/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asou <asou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 23:07:54 by asou              #+#    #+#             */
/*   Updated: 2025/03/26 23:09:56 by asou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Necessary libs:
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

// stack:
typedef struct s_stack
{
	int				*number;
	int				index;
	struct s_stack	*next;
}	t_stack;

// tools:
int		ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strdup(char *s);
long	ft_atoi(char *str);

// ft_split function:
char	**ft_split(char *s, char c);

// instructions:
void	swap(t_stack **s);
void	push(t_stack **src, t_stack **dst);
void	rotate(t_stack **s);
void	rev_rotate(t_stack **s);
void	rrr(t_stack **a, t_stack **b);

// utils (1 & 2):
int		ft_lstsize(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lst_beflast(t_stack *lst);
void	ft_lstdelone(t_stack *lst, void (*del)(void *));
void	ft_lstclear(t_stack **lst, void (*del)(void*));
void	ft_lstiter(t_stack *lst, void (*f)(int *));
t_stack	*ft_lstnew(int num);

// mini operations:
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);

// Sorting utils:
void	indexation(t_stack **s);
int		get_direction(t_stack *s, int index, int size);
void	rotate_push(t_stack **s, int index);
void	reverse_rotate_push(t_stack **s, int index);
void	sorting_back(t_stack **a, t_stack **b);
long	main_direction(t_stack **s);
void	push_chunk(t_stack **a, t_stack **b, int chunk_len);
int		is_sorted(t_stack **s);

// Parse the input:
char	**ft_join(char **s1, char **s2);
char	**validate_input(int argc, char **argv);
int		**convert_arr(char **s);
void	is_duplicated(char **s);
void	is_overflow(char **arr);

// main fuctions:
void	error(void);
void	check_args(int argc, char **argv);
t_stack	*stack_getter(char **arr);
void	sort(t_stack **a, t_stack **b);

// sorting functions:
void	sorting_2(t_stack **s);
void	sorting_3(t_stack **s);
void	sorting_4(t_stack **a, t_stack **b);
void	sorting_5(t_stack **a, t_stack **b);
void	sorting_big(t_stack **a, t_stack **b);
void	bigsort(t_stack **a, t_stack **b);

// array utils funtions:
void	ft_free(char **s);
void	ft_free_int(int **arr, int len);
int		ft_arrlen(char **arr);
int		ft_tablen(char **arr);
void	is_allowed(char *s);

#endif