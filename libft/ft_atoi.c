/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetsabe <yetsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:31:45 by yeparra-          #+#    #+#             */
/*   Updated: 2025/07/26 14:15:34 by yetsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	atol_sign_and_validate_str(const char *str, int *i, int *error)
{
	int	sign;

	sign = 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	if (str[*i] == '\0')
	{
		*error = 1;
		return (0);
	}
	return (sign);
}

long	ft_atol_strict(const char *str, int *error)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	i = 0;
	*error = 0;
	sign = atol_sign_and_validate_str(str, &i, error);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			*error = 1;
			return (0);
		}
		if (result > (LONG_MAX - (str[i] - '0')) / 10)
		{
			*error = 1;
			return (0);
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
