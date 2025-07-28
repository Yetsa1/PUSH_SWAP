/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetsabe <yetsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:37:11 by yetsabe           #+#    #+#             */
/*   Updated: 2025/07/08 14:37:11 by yetsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*Checks that arguments are valid and not empty
Displays "Error" and exits if any argument is invalid.*/
void	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
		exit(0);
	while (i < argc)
	{
		if (!argv[i] || verify_empty_or_space_str(argv[i]))
			exit_error();
		i++;
	}
}
/*Chooses which algorithm to apply based on stack size.*/
void	choose_algorithm(t_stack *a, t_stack *b)
{
	int	size;

	size = count_nodes(a);
	if (size < 2)
		return ;
	else if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size <= 10)
		sort_5(a, b);
	else
		ksort(a, b);
}
/*Main to program
Initialize both stacks as empty.
Check arguments.
Parse and create to stack 'a'
It only enters the ordering process when
there are more than two nodes.
If there are more than two nodes, apply the corresponding sort_algorithm.
And memory free.*/
int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	a.top = NULL;
	b.top = NULL;
	check_args(argc, argv);
	if (!parse_and_create_stack(argc, argv, &a))
		exit_error();
	if (count_nodes(&a) < 2)
	{
		free_stack(&a);
		return (0);
	}
	choose_algorithm(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
