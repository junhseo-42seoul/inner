/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:27:39 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/10 11:14:44 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	put_str(char *s, int *count)
{
	int	strlen;

	if (s == NULL)
	{
		error_check(write(1, "(null)", 6), count);
		return ;
	}
	strlen = ft_strlen(s);
	error_check(write(1, s, strlen), count);
	if (*count == -1)
		return ;
}
