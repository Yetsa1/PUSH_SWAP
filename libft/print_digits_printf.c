/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digits_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetsabe <yetsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:55:55 by yeparra-          #+#    #+#             */
/*   Updated: 2025/07/26 17:51:38 by yetsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_digits(int digit, int *count)
{
	char	c;

	if (digit == INT_MIN)
	{
		*count = *count + write(1, "-2147483648", 11);
		return ;
	}
	else
	{
		if (digit < 0)
		{
			*count = *count + write(1, "-", 1);
			digit = -digit;
		}
		if (digit >= 10)
		{
			print_digits((digit / 10), count);
			digit = digit % 10;
		}
		*count = *count + 1;
		c = digit + '0';
		write(1, &c, 1);
	}
}
