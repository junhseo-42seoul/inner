/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:10:01 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/16 21:28:48 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*create_buff(int fd, char **buff);
char	*ft_strjoin(char *s1, char *s2);
char	*get_string_before_newline(int index, char **save);
char	*get_last_line(int index, char **save);
char	*update_buffers(int fd, char **save, char **buff, int index);

#endif
