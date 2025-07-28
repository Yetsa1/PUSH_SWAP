/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetsabe <yetsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:21:42 by yetsabe           #+#    #+#             */
/*   Updated: 2025/07/26 19:50:02 by yetsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*Free a string array created by ft_split*/
void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}
/*Prints an error message to stderr and exits the program.*/
void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
/*Frees all nodes in a stack.*/
void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	while (stack && stack->top)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
	}
}
/*Frees tokens and the stack if a parsing error occurs.*/
int	return_error_and_free(t_stack *a, char **tokens)
{
	ft_free_split(tokens);
	free_stack(a);
	return (0);
}
