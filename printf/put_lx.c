/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_lx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:37:44 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/10 19:07:57 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void	put_lx(unsigned long long n, int *count)
{
	char	*base;
	char	tmp;

	base = "0123456789ABCDEF";
	if (n >= 16)
		put_lx(n / 16, count);
	if (*count == -1)
		return ;
	tmp = base[n % 16];
	error_check(write(1, &tmp, 1), count);
}
