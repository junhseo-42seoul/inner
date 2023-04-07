/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:37:46 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/07 19:02:09 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void	put_sx(unsigned long n, int *count)
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
