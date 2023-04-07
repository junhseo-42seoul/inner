/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:27:39 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/07 15:45:19 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	put_str(char *s, int *count)
{
	int	strlen;

	strlen = ft_strlen(s);
	write(1, s, strlen);
	*count += strlen;
}
