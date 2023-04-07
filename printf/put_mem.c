/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:38:49 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/07 19:05:52 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void	put_mem_recursive(unsigned long n, int *count)
{
	char	*base;
	char	tmp;

	base = "0123456789abcdef";
	if (n >= 16)
		put_sx(n / 16, count);
	tmp = base[n % 16];
	write(1, &tmp, 1);
	*count += 1;
}

void	put_mem(unsigned long ptr, int *count)
{
	int	depth;

	depth = 0;
	write(1, "0x", 2);
	*count += 2;
	put_mem_recursive(ptr, count);
}
