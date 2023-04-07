/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_lx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:37:44 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/07 15:38:36 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void	put_lx(unsigned int n, int *count)
{
	char	*base;
	char	tmp;

	base = "0123456789ABCDEF";
	if (n >= 16)
		put_lx(n / 16, count);
	tmp = base[n % 16];
	write(1, &tmp, 1);
	*count = *count + 1;
}
