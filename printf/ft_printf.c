/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:46:10 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/07 15:31:35 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		lst;
	int			count;
	const char	*type_specifier;

	type_specifier = "cspdiuxX%";
	va_start(lst, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			if (!is_type(type_specifier, *(++str)))
				return (-1);
			print_lst(*str, &lst, &count);
		}
		else
		{	
			write(1, str, 1);
			count++;
		}
		str++;
	}
	va_end(lst);
	return (count);
}
