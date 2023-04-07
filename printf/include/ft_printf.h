/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:54:26 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/06 11:14:43 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
int		is_type(const char *type_specifier, const char str, va_list *lst);
void	put_sx(unsigned int n, int fd);
void	put_lx(unsigned int n, int fd);
void	put_u(unsigned int n, int fd);
void	print_lst(const char type_spec, va_list *lst);

#endif