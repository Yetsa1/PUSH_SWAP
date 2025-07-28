/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetsabe <yetsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:55:55 by yeparra-          #+#    #+#             */
/*   Updated: 2025/07/26 17:48:25 by yetsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_format(char conversions, va_list args)
{
	int	count;

	count = 0;
	if (conversions == '%')
		print_char('%', &count);
	else if (conversions == 'c')
		print_char(va_arg(args, int), &count);
	else if (conversions == 's')
		ft_printstr(va_arg(args, char *), &count);
	else if (conversions == 'd')
		print_digits((va_arg(args, int)), &count);
	else if (conversions == 'i')
		print_digits((va_arg(args, int)), &count);
	else if (conversions == 'X')
		ft_print_x((va_arg(args, unsigned int)), HEXA_MAYUS, &count);
	else if (conversions == 'x')
		ft_print_x((va_arg(args, unsigned int)), HEXA_MIN, &count);
	else if (conversions == 'u')
		print_u(va_arg(args, unsigned int), &count);
	else if (conversions == 'p')
		print_point(va_arg(args, unsigned long long), &count);
	else
		count = count + write(1, &conversions, 1);
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count = count + print_format(*format, args);
		}
		else
			count = count + write(1, &*format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
