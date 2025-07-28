/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetsabe <yetsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 22:14:39 by yeparra-          #+#    #+#             */
/*   Updated: 2025/07/26 18:02:43 by yetsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define HEXA_MIN "0123456789abcdef"
# define HEXA_MAYUS "0123456789ABCDEF"
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

int			atol_sign_and_validate_str(const char *str, int *i, int *error);
long		ft_atol_strict(const char *str, int *error);
void		ft_print_x(unsigned long n, char *dictionary, int *count);
int			print_format(char conversions, va_list args);
int			ft_printf(char const *format, ...);
void		ft_printstr(char *str, int *count);
void		ft_putchar(char c);
char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		print_char(char c, int *count);
void		print_digits(int digit, int *count);
void		print_point(unsigned long long point, int *count);
void		print_u(unsigned int digit, int *count);

#endif
