/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetsabe <yetsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:55:55 by yeparra-          #+#    #+#             */
/*   Updated: 2025/07/26 17:47:40 by yetsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printstr(char *str, int *count)
{
	if (str == NULL)
	{
		*count = *count + write(1, "(null)", 6);
		return ;
	}
	*count = *count + ft_strlen(str);
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}
