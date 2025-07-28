/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetsabe <yetsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:08:08 by yetsabe           #+#    #+#             */
/*   Updated: 2025/07/26 19:48:11 by yetsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*Checks if the string is a valid number (optional +/- followed digits).*/
int	is_valid_digit(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
/*Checks if the string is empty or only contains spaces/tabs.*/
int	verify_empty_or_space_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}
/*Parses a single argument and splits it if it contains spaces.
Convert to long with error handling.
Check for duplicates or if it is out of range.
Adds the value to the end of the stack.
Free memory to tokens.
*/
int	parse_argument(char *argv, t_stack *a)
{
	char	**tokens;
	int		j;
	long	n;
	int		error_flag;

	tokens = ft_split(argv, ' ');
	if (!tokens)
		return (0);
	j = 0;
	while (tokens[j])
	{
		if (!is_valid_digit(tokens[j]))
			return (ft_free_split(tokens), 0);
		n = ft_atol_strict(tokens[j], &error_flag);
		if (error_flag || n < INT_MIN || n > INT_MAX
			|| already_stack(a, (int)n))
			return (return_error_and_free(a, tokens));
		push_bottom(a, (int)n);
		j++;
	}
	ft_free_split(tokens);
	return (1);
}
/*Parses all arguments from main and builds the stack*/
int	parse_and_create_stack(int argc, char **argv, t_stack *a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!parse_argument(argv[i], a))
			return (0);
		i++;
	}
	return (1);
}
/*Checks if a value already exists in the stack to avoid duplicates.*/
int	already_stack(t_stack *a, int value)
{
	t_node	*tmp;

	tmp = a->top;
	while (tmp)
	{
		if (tmp->value == value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
