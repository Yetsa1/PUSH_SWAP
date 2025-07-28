/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetsabe <yetsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:55:55 by yeparra-          #+#    #+#             */
/*   Updated: 2025/07/26 17:48:16 by yetsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_x(unsigned long n, char *dictionary, int *count)
{
	char	digit;

	if (n >= 16)
	{
		ft_print_x(n / 16, dictionary, count);
		n = n % 16;
	}
	digit = dictionary[n];
	*count = *count + write(1, &digit, 1);
}
