/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:37:46 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/10 13:28:39 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void	put_sx(unsigned long long n, int *count)
{
	char	*base;
	char	tmp;

	base = "0123456789abcdef";
	if (n >= 16)
		put_sx(n / 16, count);
	if (*count == -1)
		return ;
	tmp = base[n % 16];
	error_check(write(1, &tmp, 1), count);
	if (*count == -1)
		return ;
}
