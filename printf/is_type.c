/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:04:20 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/07 15:31:17 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	is_type(const char *type_specifier, const char str)
{
	if (!ft_strchr(type_specifier, str))
		return (0);
	return (1);
}
