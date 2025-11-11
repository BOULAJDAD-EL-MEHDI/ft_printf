/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:13:06 by eboulajd          #+#    #+#             */
/*   Updated: 2025/11/09 11:08:41 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	len;
	va_list args;
	va_start(args, str);

	i = 0;
	len = 0;
	while (str[i])
	{
		
	}
}
