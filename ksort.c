/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetsabe <yetsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:18:01 by yetsabe           #+#    #+#             */
/*   Updated: 2025/07/28 14:45:45 by yetsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Pushes all elements back from stack 'b' to stack 'a' in descending order.
void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	size;
	int	pos;
	int	rb_count;
	int	rrb_count;

	while (b->top)
	{
		size = count_nodes(b);
		pos = max_position(b);
		rb_count = pos;
		rrb_count = size - pos;
		if (rb_count <= rrb_count)
			while (rb_count-- > 0)
				rb(b);
		else
			while (rrb_count-- > 0)
				rrb(b);
		pa(a, b);
	}
}
// Main algortihm to sort N elements using chunk strategy
void	ksort(t_stack *a, t_stack *b)
{
	int	size;
	int	range;
	int	i;

	size = count_nodes(a);
	range = ft_sqrt(size) * 14 / 10;
	i = 0;
	index_stack(a);
	while (a->top)
	{
		if (a->top->value <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if (a->top->value <= i + range)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
	push_back_to_a(a, b);
}
// Returns the index of the largest value in the stack
int	max_position(t_stack *stack)
{
	t_node	*tmp;
	int		max;
	int		pos;
	int		i;

	tmp = stack->top;
	if (!tmp)
		return (-1);
	max = tmp->value;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->value > max)
		{
			max = tmp->value;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}
// Calculates the integer square root of a number
int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i * i <= nb)
		i++;
	return (i - 1);
}
// Counts how many nodes are in the stack
int	count_nodes(t_stack *stack)
{
	int		count;
	t_node	*tmp;

	count = 0;
	tmp = stack->top;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
