/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetsabe <yetsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:59:09 by yetsabe           #+#    #+#             */
/*   Updated: 2025/07/28 14:40:51 by yetsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Copies the stack's values into a dynamic array
int	*copy_stack_array(t_stack *a, int size)
{
	int		*array;
	t_node	*tmp;
	int		i;

	array = malloc(sizeof(int) * size);
	if (!array)
		exit_error();
	tmp = a->top;
	i = 0;
	while (i < size && tmp)
	{
		array[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (array);
}
// Sorts an array using bubble sort (sufficient for 100 of 500 elements)
void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
// Replaces stack values with their corresponding sorted indices
void	replace_values_by_indices(t_stack *a, int *array, int size)
{
	t_node	*tmp;
	int		i;

	tmp = a->top;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->value == array[i])
			{
				tmp->value = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}
// Main function: transforms values into their corresponding indices.
void	index_stack(t_stack *a)
{
	int	*array;
	int	size;

	size = count_nodes(a);
	if (size < 2)
		return ;
	array = copy_stack_array(a, size);
	sort_array(array, size);
	replace_values_by_indices(a, array, size);
	free(array);
}
