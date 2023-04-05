/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:24:11 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/05 17:31:15 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_lst(const char type_spec, va_list *lst)
{
	if (type_spec == 'c')
		ft_putchar_fd(va_arg(*lst, int), 1);
	else if (type_spec == 's')
		ft_putstr_fd(va_arg(*lst, char *), 1);
	else if (type_spec == 'p')
		put_u(va_arg(*lst, unsigned int), 1);
	else if (type_spec == 'd' || type_spec == 'i')
		ft_putnbr_fd(va_arg(*lst, int), 1);
	else if (type_spec == 'u')
		put_u(va_arg(*lst, unsigned int), 1);
	else if (type_spec == 'x')
		put_sx(va_arg(*lst, unsigned int), 1);
	else if (type_spec == 'X')
		put_lx(va_arg(*lst, unsigned int), 1);
	else if (type_spec == '%')
		write(1, "%", 1);
}
