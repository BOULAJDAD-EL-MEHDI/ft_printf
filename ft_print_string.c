/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 11:12:58 by eboulajd          #+#    #+#             */
/*   Updated: 2025/12/09 17:56:20 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_print_string(char *str)
{
	int	i;
	int	len;

	if (!str)
		return (0);
	len = str_len(str);
	i = 0;
	while (str[i])
	{
		if (write(1, &str[i], 1) != 1)
			return (-1);
		i++;
	}
	return (len);
}
