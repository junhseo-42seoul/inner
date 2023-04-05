/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_lx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:37:44 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/05 17:19:24 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	put_lx(unsigned int n, int fd)
{
	char	*base;
	char	tmp;

	base = "0123456789ABCDEF";
	if (n >= 16)
		put_lx(n / 16, fd);
	tmp = base[n % 16];
	write(fd, &tmp, 1);
}
