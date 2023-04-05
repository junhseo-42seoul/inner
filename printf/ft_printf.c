/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:46:10 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/05 22:59:42 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list		lst;
	const char	*type_specifier;

	type_specifier = "cspdiuxX%";
	va_start(lst, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (!is_type(type_specifier, *(str + 1), &lst))
				return (0);
			str++;
		}
		else
			write(1, str, 1);
		str++;
	}
	va_end(lst);
	return (0);
}
