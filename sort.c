/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetsabe <yetsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:49:43 by yetsabe           #+#    #+#             */
/*   Updated: 2025/07/28 13:45:53 by yetsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//Sorts two elements if they are in the wrong order
void	sort_2(t_stack *a)
{
	if (!a || !a->top || !a->top->next)
		return ;
	if (a->top->value > a->top->next->value)
		sa(a);
}
//Sorts three elements usging minimal instruction combinations
void	sort_3(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->top->value;
	y = a->top->next->value;
	z = a->top->next->next->value;
	if (x < y && y < z)
		return ;
	else if (x < z && z < y)
	{
		sa(a);
		ra(a);
	}
	else if (y < x && x < z)
		sa(a);
	else if (y < z && z < x)
		ra(a);
	else if (z < x && x < y)
		rra(a);
	else if (z < y && y < x)
	{
		sa(a);
		rra(a);
	}
}
//Finds the index of the smallest value in the stack.
int	find_min_index(t_stack *stack)
{
	t_node	*tmp;
	int		min;
	int		index;
	int		i;

	tmp = stack->top;
	min = tmp->value;
	index = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (index);
}
//Sorts up to 5 elements by pushing the smallest values to b and using sort_3
void	sort_5(t_stack *a, t_stack *b)
{
	int	min_index;

	if (!a || !a->top)
		return ;
	while (count_nodes(a) > 3)
	{
		min_index = find_min_index(a);
		if (min_index <= count_nodes(a) / 2)
			while (min_index-- > 0)
				ra(a);
		else
			while (min_index++ < count_nodes(a))
				rra(a);
		pb(a, b);
	}
	sort_3(a);
	while (b->top)
		pa(a, b);
}
//Same logic as sort_5 but for stacks up to 10 elements
void	sort_10(t_stack *a, t_stack *b)
{
	int	to_push;
	int	min_index;

	to_push = count_nodes(a) - 3;
	while (to_push > 0)
	{
		min_index = find_min_index(a);
		if (min_index <= count_nodes(a) / 2)
			while (min_index-- > 0)
				ra(a);
		else
			while (min_index++ < count_nodes(a))
				rra(a);
		pb(a, b);
		to_push--;
	}
	sort_3(a);
	while (b->top)
	{
		pa(a, b);
	}
}
