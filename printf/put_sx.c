/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:37:46 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/06 11:12:18 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void	put_sx(unsigned int n, int fd)
{
	char	*base;
	char	tmp;

	base = "0123456789abcdef";
	if (n >= 16)
		put_sx(n / 16, fd);
	tmp = base[n % 16];
	write(fd, &tmp, 1);
}
