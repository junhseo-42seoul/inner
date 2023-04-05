/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:54:26 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/05 18:05:03 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

void	put_sx(unsigned int n, int fd);
void	put_lx(unsigned int n, int fd);
void	put_u(unsigned int n, int fd);
void	print_lst(const char type_spec, va_list *lst);
int		is_type(const char *type_specifier, const char str, va_list *lst);

#endif