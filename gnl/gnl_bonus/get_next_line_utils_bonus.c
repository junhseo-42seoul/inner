/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:10:56 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/23 18:36:31 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//삭제할 노드를 fd + find_fd로 탐색할 것인지, 구조체 포인터를 인자로 받아 바로 해제할 것인지 고민 필요
//연결리스트 삭제 부분에서 해당 함수를 가져다 쓴다고 가정하면 구조체 포인터를 인자로 받는것이 좋아보임
void	free_node(t_list **node)
{
	free((*node)->buff);
	free((*node));
}

//리스트 맨뒤에 새로운 노드 연결
//first_node가 NULL인 경우는 고려하지 않아도 됨
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

//노드 삭제(first_node, middle-end_node 모두 처리 가능)
void	delete_node(int fd, t_head **head)
{
	t_list	*tmp;
	t_list	*del_node;

	if ((*head)->first_node->fd == fd)
	{
		tmp = (*head)->first_node;
		(*head)->first_node = tmp->next;
		free_node(&tmp);
	}
	else
	{
		tmp = (*head)->first_node;
		while (tmp->next && tmp->next->fd != fd)
			tmp = tmp->next;
		del_node = tmp->next;
		tmp->next = del_node->next;
		free_node(&del_node);
	}
	if (!(*head)->first_node)
	{
		free(*head);
		*head = NULL;
	}
}

//해당 부분 수정 후 동작여부 테스트 진행
char	*update_buffers(int fd, int index, t_head **head)
{
	t_list	*node;
	char	*buff;
	char	*tmp;

	node = find_node(fd, *head);
	buff = read_file(fd);
	if (!buff)
	{
		delete_node(fd, head);
		return (NULL);
	}
	if (*(node->buff + node->index) == '\0' && *buff == '\0')
	{
		free(buff);
		delete_node(fd, head);
		return (NULL);
	}
	if (*buff == '\0')
	{
		free(buff);
		tmp = get_string(index, (node->buff + node->index));
		delete_node(fd, head);
		return (tmp);
	}
	tmp = ft_strjoin((node->buff + node->index), buff, 0);
	free(node->buff);
	free(buff);
	node->buff = tmp;
	node->index = 0;
	return (get_next_line(fd));
}

char	*get_next_line(int fd)
{
	static t_head	*head = {NULL};
	char			*result;
	t_list			*tmp;
	int				index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!head)
	{
		head = (t_head *)malloc(sizeof(t_head));
		if (!head)
			return (NULL);
		head->first_node = create_node(fd);
		if (!head->first_node)
		{
			free(head);
			head = NULL;
			return (NULL);
		}
	}
	tmp = find_node(fd, head);
	if (!tmp)
	{
		tmp = append_node(fd, &head);
		if (!tmp)
			return (NULL);
	}
	index = 0;
	while (*(tmp->buff + tmp->index + index) != '\n' && *(tmp->buff + tmp->index + index) != '\0')
		index++;
	if (*(tmp->buff + tmp->index + index) == '\n')
	{
		result = get_string(++index, (tmp->buff + tmp->index));
		tmp->index += index;
		return (result);
	}	
	return (update_buffers(fd, index, &head));
}
