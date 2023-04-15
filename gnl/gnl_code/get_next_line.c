/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 09:52:33 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/15 14:07:18 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*bbuff;
	int			index;

	if (!create_buff(fd, &bbuff))
		return (NULL);
	index = 0;
	while (*(bbuff + index) != '\n' && *(bbuff + index) != '\0')
		index++;
	return (decision_rv(fd, &bbuff, index));
}
