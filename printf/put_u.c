/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:37:40 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/07 15:40:04 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void	put_u(unsigned int n, int *count)
{
	char	tmp;

	if (n >= 10)
		put_u(n / 10, count);
	tmp = (n % 10) + '0';
	write(1, &tmp, 1);
	*count = *count + 1;
}
