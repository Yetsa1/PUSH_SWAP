/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialice_and_print_stacks.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetsabe <yetsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:37:26 by yetsabe           #+#    #+#             */
/*   Updated: 2025/07/08 14:37:26 by yetsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*Creates a new node with a given value and returns it.*/
t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}
/*Inserts a new node at the bottom of the stack*/
void	push_bottom(t_stack *stack, int value)
{
	t_node	*new;
	t_node	*tmp;

	new = new_node(value);
	if (!new)
		return ;
	if (!stack->top)
	{
		stack->top = new;
		return ;
	}
	tmp = stack->top;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
