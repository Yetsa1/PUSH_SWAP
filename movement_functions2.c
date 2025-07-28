/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_functions2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetsabe <yetsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:19:29 by yetsabe           #+#    #+#             */
/*   Updated: 2025/07/28 14:18:32 by yetsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Roates all elements of stack a upwards
// The first element becomes the last
void	ra(t_stack *a)
{
	t_node	*first_node;
	t_node	*last_node;

	if (!a || !a->top || !a->top->next)
		return ;
	first_node = a->top;
	a->top = first_node->next;
	last_node = a->top;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = first_node;
	first_node->next = NULL;
	ft_printf("ra\n");
}
// Same as ra but for stack b
void	rb(t_stack *b)
{
	t_node	*first_node;
	t_node	*last_node;

	if (!b || !b->top || !b->top->next)
		return ;
	first_node = b->top;
	b->top = first_node->next;
	last_node = b->top;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = first_node;
	first_node->next = NULL;
	ft_printf("rb\n");
}
// Applies ra and rb simultaneously
void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}
