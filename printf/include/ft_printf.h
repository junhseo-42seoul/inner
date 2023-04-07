/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:54:26 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/07 19:03:12 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
int		is_type(const char *type_specifier, const char str);
void	put_sx(unsigned long n, int *count);
void	put_lx(unsigned long n, int *count);
void	put_u(unsigned int n, int *count);
void	put_per(int *count);
void	put_mem(unsigned long ptr, int *count);
void	print_lst(const char type_spec, va_list *lst, int *count);

#endif