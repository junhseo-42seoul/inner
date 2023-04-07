/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:38:49 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/07 18:57:39 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void	put_mem_recursive(unsigned int ptr, int depth)
{
	char	*base;
	char	tmp;

	base = "0123456789abcdef";
	if (depth < 8)
		put_mem_recursive(ptr / 16, depth + 1);
	tmp = base[ptr % 16];
	write(1, &tmp, 1);
}

void	put_mem(unsigned int ptr, int *count)
{
	int	depth;

	depth = 0;
	write(1, "0x1", 3);
	put_mem_recursive(ptr, depth);
	*count += 11;
}
