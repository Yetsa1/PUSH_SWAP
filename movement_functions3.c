/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_functions3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetsabe <yetsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 19:52:45 by yetsabe           #+#    #+#             */
/*   Updated: 2025/07/28 14:28:06 by yetsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Rotates all elements of stack a downwards
// The last element become the first
void	rra(t_stack *a)
{
	t_node	*last_node;
	t_node	*penultimate;

	if (!a || !a->top || !a->top->next)
		return ;
	penultimate = a->top;
	while (penultimate->next->next)
		penultimate = penultimate->next;
	last_node = penultimate->next;
	penultimate->next = NULL;
	last_node->next = a->top;
	a->top = last_node;
	ft_printf("rra\n");
}
// Same as rra but for stack b
void	rrb(t_stack *b)
{
	t_node	*last_node;
	t_node	*penultimate;

	if (!b || !b->top || !b->top->next)
		return ;
	penultimate = b->top;
	while (penultimate->next->next)
		penultimate = penultimate->next;
	last_node = penultimate->next;
	penultimate->next = NULL;
	last_node->next = b->top;
	b->top = last_node;
	ft_printf("rrb\n");
}
// Aplies rra and rrb simultaneously.
void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
