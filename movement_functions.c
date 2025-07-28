/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetsabe <yetsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:37:35 by yetsabe           #+#    #+#             */
/*   Updated: 2025/07/08 14:37:35 by yetsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//Swap the top elements of stack a.
void	sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (!a || !a->top || !a->top->next)
		return ;
	first = a->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	a->top = second;
	ft_printf("sa\n");
}
//Swaps the top two elements of stack b
void	sb(t_stack *b)
{
	sa(b);
	ft_printf("sb\n");
}
//Swaps the top two elements of both stacks
void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	ft_printf("ss\n");
}
//Takes the top element from stack b and pushes it to stack a
void	pa(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!b || !b->top)
		return ;
	tmp = b->top;
	b->top = b->top->next;
	tmp->next = a->top;
	a->top = tmp;
	ft_printf("pa\n");
}
//Takes the top elements from stack a and pushes it to stack b
void	pb(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!a || !a->top)
		return ;
	tmp = a->top;
	a->top = a->top->next;
	tmp->next = b->top;
	b->top = tmp;
	ft_printf("pb\n");
}
