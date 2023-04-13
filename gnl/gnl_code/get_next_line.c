/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:13:12 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/13 20:11:21 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*get_next_line(int fd)
{
	static char	*buff;
	char		*forfree;
	char		*new;
	int 		rv;
	int 		index;
	
	//정적 포인터 변수 초기화 및 NULL guard
	//별도 함수로 빼는 것도 괜찮아보임
	//인자는 fd와 buffer_size
	//리턴값이 null이라면 gnl 함수도 종료
	if (!buff)
	{
		buff = (char *)malloc(BUFFER_SIZE);
		if (!buff)
			return (NULL);
		forfree = buff;
		rv = read(fd, buff, BUFFER_SIZE);
		if (rv == -1)
			return (NULL);
	}
	
	//반복문 돌면서 \n 있는지 확인
	//조건은 \n을 찾거나 buffersize만큼 확인했을 때
	index = 0;
	while (*(buff + index) != '\n' && index < BUFFER_SIZE && *(buff + index) != '\0')
		index++;
	if (*(buff + index) == '\n')
	{
		new = (char *)malloc(index + 2);
		if (new == NULL)
			return (NULL);
		new[index + 1] = '\0';
		int i = 0;
		while (i <= index)
		{
			*(new + i) = *buff++;
			i++;
		}
	}
	else
	{
		new = (char *)malloc(index + 1);
		if (new == NULL)
			return (NULL);
		new[index] = '\0';
		int i = 0;
		while (i < index)
		{
			*(new + i) = *buff++;
			i++;
		}
	}
	printf("%s", new);
	free(new);
	return (forfree);
}

#include <fcntl.h>

int main()
{
	int fd;
	char *buff;
	char path[] = "example.txt";
	
	fd = open(path, O_RDWR);
	buff = get_next_line(fd);
	free(buff);
	close(fd);
}