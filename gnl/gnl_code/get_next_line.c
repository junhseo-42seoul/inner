/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 09:52:33 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/15 11:42:30 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*create_buff(int fd, char **buff)
{
	int		rv;

	if (*buff)
		return (*buff);
	*buff = (char *)malloc(BUFFER_SIZE + 1);
	if (*buff == NULL)
		return (NULL);
	rv = read(fd, *buff, BUFFER_SIZE);
	if (rv < 0)
	{
		free(*buff);
		return (NULL);
	}
	else if (rv == 0)
	{
		free(*buff);
		*buff = (char *)malloc(1);
		**buff = '\0';
		return (*buff);
	}
	*(*buff + BUFFER_SIZE) = '\0';
	return (*buff);
}

char *ft_strjoin(char *s1, char *s2)
{
	size_t total_len;
	char *str;
	char *new;

	total_len = 0;
	str = s1;
	while (*str++)
		total_len++;
	str = s2;
	while (*str++)
		total_len++;
	new = (char *)malloc(total_len + 1);
	if (new == NULL)
		return (NULL);
	str = new;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (new);
}

char	*get_str(int index, char **bbuff)
{
	char	*new;
	char	*buff;
	int		input_index;

	new = (char *)malloc(index + 2);
	if (!new)
	{
		free(new);
		free(*bbuff);
		return (NULL);
	}
	*(new + index) = '\n';
	*(new + index + 1) = '\0';
	input_index = -1;
	while (++input_index < index)
		*(new + input_index) = *(*bbuff + input_index);
	//bbuff 재설정 부분(함수로 넣을 것 join 사용)
	buff = ft_strjoin("", (*bbuff + index + 1));
	free(*bbuff);
	*bbuff = buff;	
	return (new);
}

char *get_last(int index, char **bbuff)
{
	char *new;
	int input_index;

	new = (char *)malloc(index + 1);
	if (!new)
	{
		free(new);
		free(*bbuff);
		return (NULL);
	}
	*(new + index) = '\0';
	input_index = -1;
	while (++input_index < index)
		*(new + input_index) = *(*bbuff + input_index);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*bbuff;
	char		*buff;
	char		*tmp;
	int			index;

	//초기 bbuff 생성
	if (!create_buff(fd, &bbuff))
		return (NULL);
	//개행 탐색
	index = 0;
	while (*(bbuff + index) != '\n' && *(bbuff + index) != '\0' && index < BUFFER_SIZE)
		index++;
	//개행 찾았으면 문자열 반환
	if (*(bbuff + index) == '\n')
		return (get_str(index, &bbuff));
	//개행 못 찾았으면 bbuff 갱신 후 다시 찾기
	//반환값에 따라 다른 동작
	//양수 = 문자열 반환
	//0 = 문자열 반환 후 종료
	//음수 = 할당 해제 후 NULL 포인터 반환
	else
	{
		buff = NULL;
		create_buff(fd, &buff);
		if (buff == NULL)
		{
			free(bbuff);
			return (NULL);
		}
		else if (*buff == '\0')
			return (get_last(index, &bbuff));
		else
		{
			tmp = ft_strjoin(bbuff, buff);
			free(buff);
			free(bbuff);
			bbuff = tmp;
			get_next_line(fd);
		}
	}
	return (get_last(index, &bbuff));
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd;
	char *str;

	char path1[] = "example.txt";
	fd = open(path1, O_RDWR);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	close(fd);
}

// else
// {
// 	new = (char *)malloc(BUFFER_SIZE + 1);
// 	if (!new)
// 	{
// 		free(bbuff);
// 		return (NULL);
// 	}
// 	rv = read(fd, new, BUFFER_SIZE);
// 	if (rv == 0)
// 	{
// 		free(new);
// 		index = 0;
// 		while (*(bbuff + index) != '\0')
// 			index++;
// 		new = (char *)malloc(index + 1);
// 		input_index = 0;
// 		while (input_index < index)
// 			*(new + input_index) = *(bbuff + input_index);
// 		*(new + index) = '\0';
// 		return (new);
// 	}
// 	else if (rv < 0)
// 	{
// 		free(new);
// 		free(bbuff);
// 		return (NULL);
// 	}
// 	// 양수일 때, 구현 필요
// 	// 단, 해당 부분은 별도 함수로 빼야할 필요 있음
// }