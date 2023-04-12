/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:24:11 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/12 10:51:34 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_lst(const char type_spec, va_list *lst, int *count)
{
	if (type_spec == 'c')
		put_chr(va_arg(*lst, int), count);
	else if (type_spec == 's')
		put_str(va_arg(*lst, char *), count);
	else if (type_spec == 'p')
		put_mem(va_arg(*lst, void *), count);
	else if (type_spec == 'd' || type_spec == 'i')
		put_nbr(va_arg(*lst, int), count);
	else if (type_spec == 'u')
		put_nbr(va_arg(*lst, unsigned int), count);
	else if (type_spec == 'x')
		put_x(va_arg(*lst, unsigned int), count, "0123456789abcdef");
	else if (type_spec == 'X')
		put_x(va_arg(*lst, unsigned int), count, "0123456789ABCDEF");
	else if (type_spec == '%')
		put_per(count);
}
