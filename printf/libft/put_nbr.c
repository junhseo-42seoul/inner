/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:38:37 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/07 17:23:23 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	put_nbr(int n, int *count)
{
	long	num;
	char	tmp;

	num = n;
	if (num < 0)
	{
		write(1, "-", 1);
		*count += 1;
		num *= -1;
	}
	if (num >= 10)
		put_nbr(num / 10, count);
	tmp = (num % 10) + '0';
	write(1, &tmp, 1);
	*count += 1;
}
