/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:38:49 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/10 12:35:26 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void	put_mem(void *ptr, int *count)
{
	unsigned long long	mem;

	mem = (unsigned long long)ptr;
	error_check(write(1, "0x", 2), count);
	if (*count == -1)
		return ;
	put_sx(mem, count);
}
