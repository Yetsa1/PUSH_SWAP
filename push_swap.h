/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetsabe <yetsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:37:41 by yetsabe           #+#    #+#             */
/*   Updated: 2025/07/08 14:37:41 by yetsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
}	t_stack;

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
int		main(int argc, char **argv);
void	exit_error(void);
int		is_valid_digit(char *str);
void	ft_free_split(char **split);
int		parse_and_create_stack(int argc, char **argv, t_stack *a);
int		already_stack(t_stack *a, int value);
int		verify_empty_or_space_str(char *str);
void	sort_2(t_stack *a);
void	sort_3(t_stack *a);
void	sort_5(t_stack *a, t_stack *b);
int		find_min_index(t_stack *stack);
void	sort_10(t_stack *a, t_stack *b);
void	free_stack(t_stack *stack);
int		*copy_stack_array(t_stack *a, int size);
void	sort_array(int *array, int size);
void	replace_values_by_indices(t_stack *a, int *array, int size);
void	index_stack(t_stack *a);
void	ksort(t_stack *a, t_stack *b);
int		max_position(t_stack *stack);
void	push_back_to_a(t_stack *a, t_stack *b);
int		return_error_and_free(t_stack *a, char **tokens);
int		parse_argument(char *argv, t_stack *a);
int		ft_sqrt(int nb);
void	check_args(int argc, char **argv);
void	choose_algorithm(t_stack *a, t_stack *b);
int		count_nodes(t_stack *stack);
t_node	*new_node(int value);
void	push_bottom(t_stack *stack, int value);
int	verify_sort(t_stack *a);

#endif
