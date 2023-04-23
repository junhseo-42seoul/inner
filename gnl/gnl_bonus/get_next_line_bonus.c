/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:13:05 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/23 20:18:18 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//해당 함수에서 구조체의 인덱스 증가를 담당해도 되나, 복잡도가 증가할것으로 보여 보류.
//이를 해결하기 위해 본 함수에서 char *result를 선언 후, gsbn의 결과를 result에 담고
//tmp.index를 증가시킨 후 return.
char	*get_string(int index, char *buff)
{
	char	*new;
	int		input_index;

	new = (char *)malloc(index + 1);
	if (!new)
	{
		new = (char *)malloc(1);
		if (!new)
			return (NULL);
		*new = '\0';
		return (new);
	}
	*(new + index) = '\0';
	input_index = -1;
	while (++input_index < index)
		*(new + input_index) = *(buff + input_index);
	return (new);
}

//해당 fd로 생성된 노드가 있는지 탐색 필요
t_list	*find_node(int fd, t_head *head)
{
	t_list	*list;

	list = head->first_node;
	while (list)
	{
		if (list->fd == fd)
			return (list);
		list = list->next;
	}
	return (NULL);
}

//node 생성만
t_list	*create_node(int fd)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->buff = read_file(fd);
	if (!new_node->buff)
	{
		free(new_node);
		return (NULL);
	}
	new_node->fd = fd;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

#include <string.h>
char	*ft_strjoin(char *s1, char *s2, size_t total_len)
{
	char	*str;
	char	*new;

	str = s1;
	while (*str++)
		total_len++;
	str = s2;
	while (*str++)
		total_len++;
	new = (char *)malloc(total_len + 1);
	if (!new)
	{
		new = malloc(1);
		if (!new)
			return (NULL);
		*new = '\0';
		return (new);
	}
	str = new;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (new);
}

//파일을 BUFFER_SIZE만큼 읽고 해당 문자열을 반환
char	*read_file(int fd)
{
	char	*new;
	int		rv;

	new = (char *)malloc(BUFFER_SIZE + 1);
	if (!new)
		return (NULL);
	rv = read(fd, new, BUFFER_SIZE);
	if (rv < 0)
	{
		free(new);
		return (NULL);
	}
	else if (rv == 0)
		*new = '\0';
	else
		*(new + rv) = '\0';
	return (new);
}
