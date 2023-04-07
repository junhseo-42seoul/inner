/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:38:49 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/07 19:00:38 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void	put_mem(unsigned int ptr, int *count)
{
	int	depth;

	depth = 0;
	write(1, "0x", 2);
	put_sx(ptr, count);
}
