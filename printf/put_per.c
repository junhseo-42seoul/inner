/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_per.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:04:06 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/12 10:50:01 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_per(int *count)
{
	error_check(write(1, "%", 1), count);
}
