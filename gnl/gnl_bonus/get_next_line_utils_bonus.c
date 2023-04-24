/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:10:56 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/24 13:28:48 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

t_list	*find_node(int fd, t_head **head)
{
	t_list	*list;
	t_list	*append_result;

	list = (*head)->first_node;
	while (list)
	{
		if (list->fd == fd)
			return (list);
		list = list->next;
	}
	append_result = append_node(fd, head);
	if (append_result)
		return (append_result);
	return (NULL);
}

t_list	*append_node(int fd, t_head **head)
{
	t_list	*lst;
	t_list	*new;

	lst = (*head)->first_node;
	while (lst->next)
		lst = lst->next;
	new = create_node(fd);
	if (!new)
		return (NULL);
	lst->next = new;
	return (new);
}

void	delete_node(int fd, t_head **head)
{
	t_list	*tmp;
	t_list	*del_node;

	if ((*head)->first_node->fd == fd)
	{
		tmp = (*head)->first_node;
		(*head)->first_node = tmp->next;
		free(tmp->buff);
		free(tmp);
	}
	else
	{
		tmp = (*head)->first_node;
		while (tmp->next && tmp->next->fd != fd)
			tmp = tmp->next;
		del_node = tmp->next;
		tmp->next = del_node->next;
		free(del_node->buff);
		free(del_node);
	}
	if (!(*head)->first_node)
	{
		free(*head);
		*head = NULL;
	}
}
