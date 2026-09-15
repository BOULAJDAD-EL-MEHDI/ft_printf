/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:13:06 by eboulajd          #+#    #+#             */
/*   Updated: 2025/12/09 18:06:31 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	handle_format(char c, va_list *args)
{
	if (c == 'c')
		return (ft_print_char(va_arg(*args, int)));
	else if (c == 's')
		return (ft_print_string(va_arg(*args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_decimal(va_arg(*args, int)));
	else if (c == 'u')
		return (print_unsigned_decimal(va_arg(*args, unsigned int)));
	else if (c == 'x')
		return (ft_print_lhex(va_arg(*args, unsigned int)));
	else if (c == 'X')
		return (ft_print_uhex(va_arg(*args, unsigned int)));
	else if (c == 'p')
		return (ft_print_pointer(va_arg(*args, void *)));
	else if (c == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;
	int		written;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
			{
				len = -1;
				break ;
			}
			written = handle_format(format[i], &args);
		}
		else
			written = ft_print_char(format[i]);
		if (written < 0)
		{
			len = -1;
			break ;
		}
		len += written;
		i++;
	}
	va_end(args);
	return (len);
}
